/* impl.c.arenacl: ARENA CLASS USING CLIENT MEMORY
 *
 * $Id$
 * $HopeName: MMsrc!arenacl.c(trunk.24) $
 * Copyright (c) 2001 Ravenbrook Limited.
 * 
 * .design: See design.mps.arena.client.
 * 
 * .improve.remember: One possible performance improvement is to
 * remember (a conservative approximation to) the indices of the first
 * and last free pages in each chunk, and start searching from these
 * in ChunkAlloc.  See request.epcore.170534.
 */

#include "boot.h"
#include "tract.h"
#include "mpm.h"
#include "mpsacl.h"

SRCID(arenacl, "$Id$");


/* ClientArenaStruct -- Client Arena Structure */

#define ClientArenaSig ((Sig)0x519A6EC7) /* SIGnature AREna CLient */

typedef struct ClientArenaStruct {
  ArenaStruct arenaStruct; /* generic arena structure */
  Sig sig;                 /* design.mps.sig */
} ClientArenaStruct;
typedef struct ClientArenaStruct *ClientArena;

#define Arena2ClientArena(arena) PARENT(ClientArenaStruct, arenaStruct, arena)
#define ClientArena2Arena(clArena) (&(clArena)->arenaStruct)


/* CLChunk -- chunk structure */

typedef struct ClientChunkStruct *ClientChunk;

#define ClientChunkSig ((Sig)0x519A6C2C) /* SIGnature ARena CLient Chunk */

typedef struct ClientChunkStruct {
  ChunkStruct chunkStruct;     /* generic chunk */
  Size freePages;              /* number of free pages in chunk */
  Addr pageBase;               /* base of first managed page in chunk */
  Sig sig;                     /* design.mps.sig */
} ClientChunkStruct;

#define ClientChunk2Chunk(clchunk) (&(clchunk)->chunkStruct)
#define Chunk2ClientChunk(chunk) PARENT(ClientChunkStruct, chunkStruct, chunk)


/* ClientChunkClientArena -- get the client arena from a client chunk */

#define ClientChunkClientArena(clchunk) \
  Arena2ClientArena(ChunkArena(ClientChunk2Chunk(clchunk)))


/* ClientChunkCheck -- check the consistency of a client chunk */

static Bool ClientChunkCheck(ClientChunk clChunk)
{
  Chunk chunk;

  CHECKS(ClientChunk, clChunk);
  chunk = ClientChunk2Chunk(clChunk);
  CHECKL(ChunkCheck(chunk));
  CHECKL(clChunk->freePages <= chunk->pages);
  /* check they don't overlap (knowing the order) */
  CHECKL((Addr)(chunk + 1) < (Addr)chunk->allocTable);
  return TRUE;
}
  

/* ClientArenaCheck -- check the consistency of a client arena */

static Bool ClientArenaCheck(ClientArena clientArena)
{
  CHECKS(ClientArena, clientArena);
  CHECKD(Arena, ClientArena2Arena(clientArena));
  return TRUE;
}


/* clientChunkCreate -- create a ClientChunk */

static Res clientChunkCreate(Chunk *chunkReturn, Addr base, Addr limit,
                             ClientArena clientArena)
{
  ClientChunk clChunk;
  Chunk chunk;
  Addr alignedBase;
  BootBlockStruct bootStruct;
  BootBlock boot = &bootStruct;
  Res res;
  void *p;

  AVER(chunkReturn != NULL);
  AVER(base != (Addr)0);
  /* @@@@ Should refuse on small chunks, instead of AVERring. */
  AVER(limit != (Addr)0);
  AVER(limit > base);

  /* Initialize boot block. */
  /* Chunk has to be page-aligned, and the boot allocs must be within it. */
  alignedBase = AddrAlignUp(base, ARENA_CLIENT_PAGE_SIZE);
  AVER(alignedBase < limit);
  res = BootBlockInit(boot, (void *)alignedBase, (void *)limit);
  if (res != ResOK)
    goto failBootInit;

  /* Allocate the chunk. */
  /* See design.mps.arena.@@@@ */
  res = BootAlloc(&p, boot, sizeof(ClientChunkStruct), MPS_PF_ALIGN);
  if (res != ResOK)
    goto failChunkAlloc;
  clChunk = p;  chunk = ClientChunk2Chunk(clChunk);

  res = ChunkInit(chunk, ClientArena2Arena(clientArena),
                  alignedBase, AddrAlignDown(limit, ARENA_CLIENT_PAGE_SIZE),
                  ARENA_CLIENT_PAGE_SIZE, boot);
  if (res != ResOK)
    goto failChunkInit;

  ClientArena2Arena(clientArena)->committed +=
    AddrOffset(base, PageIndexBase(chunk, chunk->allocBase));
  BootBlockFinish(boot);

  clChunk->sig = ClientChunkSig;
  AVERT(ClientChunk, clChunk);
  *chunkReturn = chunk;
  return ResOK;

failChunkInit:
failChunkAlloc:
failBootInit:
  return res;
}


/* ClientChunkInit -- initialize a ClientChunk */

static Res ClientChunkInit(Chunk chunk, BootBlock boot)
{
  ClientChunk clChunk;

  /* chunk is supposed to be uninitialized, so don't check it. */
  clChunk = Chunk2ClientChunk(chunk);
  AVERT(BootBlock, boot);
  UNUSED(boot);

  clChunk->freePages = chunk->pages; /* too large @@@@ */

  return ResOK;
}


/* clientChunkDestroy -- destroy a ClientChunk */

static void clientChunkDestroy(Chunk chunk)
{
  ClientChunk clChunk;

  clChunk = Chunk2ClientChunk(chunk);
  AVERT(ClientChunk, clChunk);

  clChunk->sig = SigInvalid;
  ChunkFinish(chunk);
}


/* ClientChunkFinish -- finish a ClientChunk */

static void ClientChunkFinish(Chunk chunk)
{
  /* Can't check chunk as it's not valid anymore. */
  UNUSED(chunk); NOOP;
}


/* ClientArenaInit -- create and initialize the client arena
 *
 * .init.memory: Creates the arena structure in the chuck given, and
 * makes the first chunk from the memory left over.
 * .arena.init: Once the arena has been allocated, we call ArenaInit
 * to do the generic part of init.
 */
static Res ClientArenaInit(Arena *arenaReturn, ArenaClass class,
                           va_list args)
{
  Arena arena;
  ClientArena clientArena;
  Size size;
  Size clArenaSize;   /* aligned size of ClientArenaStruct */
  Addr base, limit, chunkBase;
  Res res;
  Chunk chunk;
  
  size = va_arg(args, Size);
  base = va_arg(args, Addr);
  AVER(arenaReturn != NULL);
  AVER((ArenaClass)mps_arena_class_cl() == class);
  AVER(base != (Addr)0);

  clArenaSize = SizeAlignUp(sizeof(ClientArenaStruct), MPS_PF_ALIGN); 
  if (size < clArenaSize) 
    return ResMEMORY;

  limit = AddrAdd(base, size);

  /* allocate the arena */
  base = AddrAlignUp(base, MPS_PF_ALIGN);
  clientArena = (ClientArena)base;
  chunkBase = AddrAlignUp(AddrAdd(base, clArenaSize), MPS_PF_ALIGN);
  if (chunkBase > limit)
    return ResMEMORY;

  arena = ClientArena2Arena(clientArena);
  /* impl.c.arena.init.caller */
  res = ArenaInit(arena, class);
  if (res != ResOK)
    return res;

  /* have to have a valid arena before calling ChunkCreate */
  clientArena->sig = ClientArenaSig;

  res = clientChunkCreate(&chunk, chunkBase, limit, clientArena);
  if (res != ResOK)
    goto failChunkCreate;
  arena->primary = chunk;

  /* Set the zone shift to divide the initial chunk into the same */
  /* number of zones as will fit into a reference set (the number of */
  /* bits in a word). Note that some zones are discontiguous in the */
  /* arena if the size is not a power of 2. */
  arena->zoneShift = SizeFloorLog2(size >> MPS_WORD_SHIFT);

  EVENT_PWA(ArenaCreateCL, arena, size, base);
  AVERT(ClientArena, clientArena);
  *arenaReturn = arena;
  return ResOK;

failChunkCreate:
  ArenaFinish(arena);
  return res;
}


/* ClientArenaFinish -- finish the arena */

static void ClientArenaFinish(Arena arena)
{
  ClientArena clientArena;
  Ring node, next;

  clientArena = Arena2ClientArena(arena);
  AVERT(ClientArena, clientArena);

  /* destroy all chunks */
  RING_FOR(node, &arena->chunkRing, next) {
    Chunk chunk = RING_ELT(Chunk, chunkRing, node);
    clientChunkDestroy(chunk);
  }

  clientArena->sig = SigInvalid;

  ArenaFinish(arena); /* impl.c.arena.finish.caller */
}


/* ClientArenaExtend -- extend the arena */

static Res ClientArenaExtend(Arena arena, Addr base, Size size)
{
  ClientArena clientArena;
  Chunk chunk;
  Res res;
  Addr limit;

  AVERT(Arena, arena);
  AVER(base != (Addr)0);
  AVER(size > 0);
  limit = AddrAdd(base, size);
  
  clientArena = Arena2ClientArena(arena);
  res = clientChunkCreate(&chunk, base, limit, clientArena);
  return res;
}


/* ClientArenaReserved -- return the amount of reserved address space */

static Size ClientArenaReserved(Arena arena)
{
  Size size;
  Ring node, nextNode;

  AVERT(Arena, arena);

  size = 0;
  /* .req.extend.slow */
  RING_FOR(node, &arena->chunkRing, nextNode) { 
    Chunk chunk = RING_ELT(Chunk, chunkRing, node);
    AVERT(Chunk, chunk);
    size += AddrOffset(chunk->base, chunk->limit);
  }

  return size;
}


/* chunkAlloc -- allocate some tracts in a chunk */

static Res chunkAlloc(Addr *baseReturn, Tract *baseTractReturn,
                      SegPref pref, Size pages, Pool pool, Chunk chunk)
{
  Index baseIndex, limitIndex, index;
  Bool b;
  Arena arena;
  ClientChunk clChunk;

  AVER(baseReturn != NULL);
  AVER(baseTractReturn != NULL);
  clChunk = Chunk2ClientChunk(chunk);

  if (pages > clChunk->freePages)
    return ResRESOURCE;

  arena = chunk->arena;

  if (pref->high)
    b = BTFindShortResRangeHigh(&baseIndex, &limitIndex, chunk->allocTable,
				chunk->allocBase, chunk->pages, pages);
  else 
    b = BTFindShortResRange(&baseIndex, &limitIndex, chunk->allocTable,
			    chunk->allocBase, chunk->pages, pages);

  if (!b)
    return ResRESOURCE;

  /* Check commit limit.  Note that if there are multiple reasons */
  /* for failing the allocation we attempt to return other result codes */
  /* in preference to ResCOMMIT_LIMIT.  See design.mps.arena.commit-limit */
  if (ArenaCommitted(arena) + pages * ChunkPageSize(chunk)
      > arena->commitLimit) {
    return ResCOMMIT_LIMIT;
  }

  /* Initialize the generic tract structures. */
  AVER(limitIndex > baseIndex);
  for(index = baseIndex; index < limitIndex; ++index) {
    PageAlloc(chunk, index, pool);
  }

  clChunk->freePages -= pages;

  *baseReturn = PageIndexBase(chunk, baseIndex);
  *baseTractReturn = PageTract(&chunk->pageTable[baseIndex]);

  return ResOK;
}


/* ClientAlloc -- allocate a region from the arena */

static Res ClientAlloc(Addr *baseReturn, Tract *baseTractReturn,
                       SegPref pref, Size size, Pool pool)
{
  Arena arena;
  Res res;
  Ring node, nextNode;
  Size pages;

  AVER(baseReturn != NULL);
  AVER(baseTractReturn != NULL);
  AVERT(SegPref, pref);
  AVER(size > 0);
  AVERT(Pool, pool);

  arena = PoolArena(pool);
  AVERT(Arena, arena);
  /* All chunks have same pageSize. */
  AVER(SizeIsAligned(size, ChunkPageSize(arena->primary)));
  /* NULL is used as a discriminator (see */
  /* design.mps.arenavm.table.disc), therefore the real pool */
  /* must be non-NULL. */
  AVER(pool != NULL);

  pages = ChunkSizeToPages(arena->primary, size);

  /* .req.extend.slow */
  RING_FOR(node, &arena->chunkRing, nextNode) { 
    Chunk chunk = RING_ELT(Chunk, chunkRing, node);
    res = chunkAlloc(baseReturn, baseTractReturn, pref, pages, pool, chunk);
    if (res == ResOK || res == ResCOMMIT_LIMIT) {
      return res;
    }
  }
  return ResRESOURCE;
}


/* ClientFree - free a region in the arena */

static void ClientFree(Addr base, Size size, Pool pool)
{
  Arena arena;
  Chunk chunk;
  Size pages;
  ClientArena clientArena;
  Index pi, baseIndex, limitIndex;
  Bool foundChunk;
  ClientChunk clChunk;

  AVER(base != NULL);
  AVER(size > (Size)0);
  AVERT(Pool, pool);
  arena = PoolArena(pool);
  AVERT(Arena, arena);
  clientArena = Arena2ClientArena(arena);
  AVERT(ClientArena, clientArena);
  AVER(SizeIsAligned(size, ChunkPageSize(arena->primary)));
  AVER(AddrIsAligned(base, ChunkPageSize(arena->primary)));

  foundChunk = ChunkOfAddr(&chunk, arena, base);
  AVER(foundChunk);
  clChunk = Chunk2ClientChunk(chunk);
  AVERT(ClientChunk, clChunk);

  pages = ChunkSizeToPages(chunk, size);
  baseIndex = INDEX_OF_ADDR(chunk, base);
  limitIndex = baseIndex + pages;
  AVER(baseIndex < limitIndex);
  AVER(limitIndex <= chunk->pages);

  for(pi = baseIndex; pi < limitIndex; pi++) {
    Page page = &chunk->pageTable[pi];
    Tract tract = PageTract(page);

    AVER(TractPool(tract) == pool);
    TractFinish(tract);
  }

  AVER(BTIsSetRange(chunk->allocTable, baseIndex, limitIndex));
  BTResRange(chunk->allocTable, baseIndex, limitIndex);

  clChunk->freePages += pages;
}


/* ClientArenaClass  -- The Client arena class definition */

DEFINE_ARENA_CLASS(ClientArenaClass, this)
{
  INHERIT_CLASS(this, AbstractArenaClass);
  this->name = "CL";
  this->size = sizeof(ClientArenaStruct);
  this->offset = offsetof(ClientArenaStruct, arenaStruct);
  this->init = ClientArenaInit;
  this->finish = ClientArenaFinish;
  this->reserved = ClientArenaReserved;
  this->extend = ClientArenaExtend;
  this->alloc = ClientAlloc;
  this->free = ClientFree;
  this->chunkInit = ClientChunkInit;
  this->chunkFinish = ClientChunkFinish;
}


/* mps_arena_class_cl -- return the arena class CL */

mps_arena_class_t mps_arena_class_cl(void)
{
  return (mps_arena_class_t)EnsureClientArenaClass();
}
