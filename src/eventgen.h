/* impl.h.eventgen -- Automatic event header
 *
 * $HopeName$
 *
 * DO NOT EDIT THIS FILE!
 * This file was generated by MMsrc!eventgen.pl(trunk.11) $
 */

#ifdef EVENT

typedef struct {
  Word code;
  Word clock;
} Event0Struct;

#define EVENT_0_FIELD_PTR(event, i) \
  (NULL)

typedef struct {
  Word code;
  Word clock;
  Addr a0;
} EventAStruct;

#define EVENT_A_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->a.a0) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  Addr a0;
  Word w1;
} EventAWStruct;

#define EVENT_AW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->aw.a0) \
   : ((i) == 1) ? (void *)&((event)->aw.w1) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
} EventPStruct;

#define EVENT_P_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->p.p0) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Addr a1;
  Addr a2;
} EventPAAStruct;

#define EVENT_PAA_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->paa.p0) \
   : ((i) == 1) ? (void *)&((event)->paa.a1) \
   : ((i) == 2) ? (void *)&((event)->paa.a2) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Addr a1;
  Word w2;
} EventPAWStruct;

#define EVENT_PAW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->paw.p0) \
   : ((i) == 1) ? (void *)&((event)->paw.a1) \
   : ((i) == 2) ? (void *)&((event)->paw.w2) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Addr a1;
  Word w2;
  Addr a3;
} EventPAWAStruct;

#define EVENT_PAWA_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pawa.p0) \
   : ((i) == 1) ? (void *)&((event)->pawa.a1) \
   : ((i) == 2) ? (void *)&((event)->pawa.w2) \
   : ((i) == 3) ? (void *)&((event)->pawa.a3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  double d1;
  double d2;
  Word w3;
  Word w4;
  Word w5;
} EventPDDWWWStruct;

#define EVENT_PDDWWW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pddwww.p0) \
   : ((i) == 1) ? (void *)&((event)->pddwww.d1) \
   : ((i) == 2) ? (void *)&((event)->pddwww.d2) \
   : ((i) == 3) ? (void *)&((event)->pddwww.w3) \
   : ((i) == 4) ? (void *)&((event)->pddwww.w4) \
   : ((i) == 5) ? (void *)&((event)->pddwww.w5) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
} EventPPStruct;

#define EVENT_PP_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pp.p0) \
   : ((i) == 1) ? (void *)&((event)->pp.p1) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  Addr a2;
  unsigned u3;
} EventPPAUStruct;

#define EVENT_PPAU_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppau.p0) \
   : ((i) == 1) ? (void *)&((event)->ppau.p1) \
   : ((i) == 2) ? (void *)&((event)->ppau.a2) \
   : ((i) == 3) ? (void *)&((event)->ppau.u3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  Addr a2;
  Word w3;
  void * p4;
} EventPPAWPStruct;

#define EVENT_PPAWP_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppawp.p0) \
   : ((i) == 1) ? (void *)&((event)->ppawp.p1) \
   : ((i) == 2) ? (void *)&((event)->ppawp.a2) \
   : ((i) == 3) ? (void *)&((event)->ppawp.w3) \
   : ((i) == 4) ? (void *)&((event)->ppawp.p4) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  void * p2;
} EventPPPStruct;

#define EVENT_PPP_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppp.p0) \
   : ((i) == 1) ? (void *)&((event)->ppp.p1) \
   : ((i) == 2) ? (void *)&((event)->ppp.p2) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  void * p2;
  Addr a3;
} EventPPPAStruct;

#define EVENT_PPPA_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pppa.p0) \
   : ((i) == 1) ? (void *)&((event)->pppa.p1) \
   : ((i) == 2) ? (void *)&((event)->pppa.p2) \
   : ((i) == 3) ? (void *)&((event)->pppa.a3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  void * p2;
  unsigned u3;
} EventPPPUStruct;

#define EVENT_PPPU_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pppu.p0) \
   : ((i) == 1) ? (void *)&((event)->pppu.p1) \
   : ((i) == 2) ? (void *)&((event)->pppu.p2) \
   : ((i) == 3) ? (void *)&((event)->pppu.u3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  void * p2;
  unsigned u3;
  unsigned u4;
} EventPPPUUStruct;

#define EVENT_PPPUU_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pppuu.p0) \
   : ((i) == 1) ? (void *)&((event)->pppuu.p1) \
   : ((i) == 2) ? (void *)&((event)->pppuu.p2) \
   : ((i) == 3) ? (void *)&((event)->pppuu.u3) \
   : ((i) == 4) ? (void *)&((event)->pppuu.u4) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  unsigned u2;
} EventPPUStruct;

#define EVENT_PPU_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppu.p0) \
   : ((i) == 1) ? (void *)&((event)->ppu.p1) \
   : ((i) == 2) ? (void *)&((event)->ppu.u2) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  unsigned u2;
  unsigned u3;
} EventPPUUStruct;

#define EVENT_PPUU_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppuu.p0) \
   : ((i) == 1) ? (void *)&((event)->ppuu.p1) \
   : ((i) == 2) ? (void *)&((event)->ppuu.u2) \
   : ((i) == 3) ? (void *)&((event)->ppuu.u3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  unsigned u2;
  Word w3;
  Word w4;
  Word w5;
} EventPPUWWWStruct;

#define EVENT_PPUWWW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppuwww.p0) \
   : ((i) == 1) ? (void *)&((event)->ppuwww.p1) \
   : ((i) == 2) ? (void *)&((event)->ppuwww.u2) \
   : ((i) == 3) ? (void *)&((event)->ppuwww.w3) \
   : ((i) == 4) ? (void *)&((event)->ppuwww.w4) \
   : ((i) == 5) ? (void *)&((event)->ppuwww.w5) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  Word w2;
  Word w3;
} EventPPWWStruct;

#define EVENT_PPWW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppww.p0) \
   : ((i) == 1) ? (void *)&((event)->ppww.p1) \
   : ((i) == 2) ? (void *)&((event)->ppww.w2) \
   : ((i) == 3) ? (void *)&((event)->ppww.w3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  Word w2;
  Word w3;
  Word w4;
} EventPPWWWStruct;

#define EVENT_PPWWW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppwww.p0) \
   : ((i) == 1) ? (void *)&((event)->ppwww.p1) \
   : ((i) == 2) ? (void *)&((event)->ppwww.w2) \
   : ((i) == 3) ? (void *)&((event)->ppwww.w3) \
   : ((i) == 4) ? (void *)&((event)->ppwww.w4) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  void * p1;
  Word w2;
  Word w3;
  Word w4;
  unsigned u5;
  unsigned u6;
  unsigned u7;
} EventPPWWWUUUStruct;

#define EVENT_PPWWWUUU_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ppwwwuuu.p0) \
   : ((i) == 1) ? (void *)&((event)->ppwwwuuu.p1) \
   : ((i) == 2) ? (void *)&((event)->ppwwwuuu.w2) \
   : ((i) == 3) ? (void *)&((event)->ppwwwuuu.w3) \
   : ((i) == 4) ? (void *)&((event)->ppwwwuuu.w4) \
   : ((i) == 5) ? (void *)&((event)->ppwwwuuu.u5) \
   : ((i) == 6) ? (void *)&((event)->ppwwwuuu.u6) \
   : ((i) == 7) ? (void *)&((event)->ppwwwuuu.u7) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  unsigned u1;
} EventPUStruct;

#define EVENT_PU_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pu.p0) \
   : ((i) == 1) ? (void *)&((event)->pu.u1) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
} EventPWStruct;

#define EVENT_PW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pw.p0) \
   : ((i) == 1) ? (void *)&((event)->pw.w1) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  Addr a2;
} EventPWAStruct;

#define EVENT_PWA_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pwa.p0) \
   : ((i) == 1) ? (void *)&((event)->pwa.w1) \
   : ((i) == 2) ? (void *)&((event)->pwa.a2) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  Addr a2;
  Word w3;
} EventPWAWStruct;

#define EVENT_PWAW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pwaw.p0) \
   : ((i) == 1) ? (void *)&((event)->pwaw.w1) \
   : ((i) == 2) ? (void *)&((event)->pwaw.a2) \
   : ((i) == 3) ? (void *)&((event)->pwaw.w3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  void * p2;
} EventPWPStruct;

#define EVENT_PWP_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pwp.p0) \
   : ((i) == 1) ? (void *)&((event)->pwp.w1) \
   : ((i) == 2) ? (void *)&((event)->pwp.p2) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  unsigned u2;
} EventPWUStruct;

#define EVENT_PWU_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pwu.p0) \
   : ((i) == 1) ? (void *)&((event)->pwu.w1) \
   : ((i) == 2) ? (void *)&((event)->pwu.u2) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  Word w2;
} EventPWWStruct;

#define EVENT_PWW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pww.p0) \
   : ((i) == 1) ? (void *)&((event)->pww.w1) \
   : ((i) == 2) ? (void *)&((event)->pww.w2) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  Word w2;
  Word w3;
  Word w4;
  double d5;
  double d6;
} EventPWWWWDDStruct;

#define EVENT_PWWWWDD_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pwwwwdd.p0) \
   : ((i) == 1) ? (void *)&((event)->pwwwwdd.w1) \
   : ((i) == 2) ? (void *)&((event)->pwwwwdd.w2) \
   : ((i) == 3) ? (void *)&((event)->pwwwwdd.w3) \
   : ((i) == 4) ? (void *)&((event)->pwwwwdd.w4) \
   : ((i) == 5) ? (void *)&((event)->pwwwwdd.d5) \
   : ((i) == 6) ? (void *)&((event)->pwwwwdd.d6) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  Word w2;
  Word w3;
  Word w4;
  Word w5;
} EventPWWWWWStruct;

#define EVENT_PWWWWW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pwwwww.p0) \
   : ((i) == 1) ? (void *)&((event)->pwwwww.w1) \
   : ((i) == 2) ? (void *)&((event)->pwwwww.w2) \
   : ((i) == 3) ? (void *)&((event)->pwwwww.w3) \
   : ((i) == 4) ? (void *)&((event)->pwwwww.w4) \
   : ((i) == 5) ? (void *)&((event)->pwwwww.w5) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  Word w2;
  Word w3;
  Word w4;
  Word w5;
  Word w6;
  Word w7;
  Word w8;
  Word w9;
} EventPWWWWWWWWWStruct;

#define EVENT_PWWWWWWWWW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pwwwwwwwww.p0) \
   : ((i) == 1) ? (void *)&((event)->pwwwwwwwww.w1) \
   : ((i) == 2) ? (void *)&((event)->pwwwwwwwww.w2) \
   : ((i) == 3) ? (void *)&((event)->pwwwwwwwww.w3) \
   : ((i) == 4) ? (void *)&((event)->pwwwwwwwww.w4) \
   : ((i) == 5) ? (void *)&((event)->pwwwwwwwww.w5) \
   : ((i) == 6) ? (void *)&((event)->pwwwwwwwww.w6) \
   : ((i) == 7) ? (void *)&((event)->pwwwwwwwww.w7) \
   : ((i) == 8) ? (void *)&((event)->pwwwwwwwww.w8) \
   : ((i) == 9) ? (void *)&((event)->pwwwwwwwww.w9) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  void * p0;
  Word w1;
  Word w2;
  Word w3;
  Word w4;
  Word w5;
  Word w6;
  Word w7;
  Word w8;
  Word w9;
  Word w10;
  Word w11;
  Word w12;
} EventPWWWWWWWWWWWWStruct;

#define EVENT_PWWWWWWWWWWWW_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->pwwwwwwwwwwww.p0) \
   : ((i) == 1) ? (void *)&((event)->pwwwwwwwwwwww.w1) \
   : ((i) == 2) ? (void *)&((event)->pwwwwwwwwwwww.w2) \
   : ((i) == 3) ? (void *)&((event)->pwwwwwwwwwwww.w3) \
   : ((i) == 4) ? (void *)&((event)->pwwwwwwwwwwww.w4) \
   : ((i) == 5) ? (void *)&((event)->pwwwwwwwwwwww.w5) \
   : ((i) == 6) ? (void *)&((event)->pwwwwwwwwwwww.w6) \
   : ((i) == 7) ? (void *)&((event)->pwwwwwwwwwwww.w7) \
   : ((i) == 8) ? (void *)&((event)->pwwwwwwwwwwww.w8) \
   : ((i) == 9) ? (void *)&((event)->pwwwwwwwwwwww.w9) \
   : ((i) == 10) ? (void *)&((event)->pwwwwwwwwwwww.w10) \
   : ((i) == 11) ? (void *)&((event)->pwwwwwwwwwwww.w11) \
   : ((i) == 12) ? (void *)&((event)->pwwwwwwwwwwww.w12) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  unsigned u0;
  unsigned u1;
  void * p2;
  Addr a3;
} EventUUPAStruct;

#define EVENT_UUPA_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->uupa.u0) \
   : ((i) == 1) ? (void *)&((event)->uupa.u1) \
   : ((i) == 2) ? (void *)&((event)->uupa.p2) \
   : ((i) == 3) ? (void *)&((event)->uupa.a3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  unsigned u0;
  unsigned u1;
  void * p2;
  void * p3;
} EventUUPPStruct;

#define EVENT_UUPP_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->uupp.u0) \
   : ((i) == 1) ? (void *)&((event)->uupp.u1) \
   : ((i) == 2) ? (void *)&((event)->uupp.p2) \
   : ((i) == 3) ? (void *)&((event)->uupp.p3) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  unsigned u0;
  unsigned u1;
  void * p2;
  void * p3;
  void * p4;
} EventUUPPPStruct;

#define EVENT_UUPPP_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->uuppp.u0) \
   : ((i) == 1) ? (void *)&((event)->uuppp.u1) \
   : ((i) == 2) ? (void *)&((event)->uuppp.p2) \
   : ((i) == 3) ? (void *)&((event)->uuppp.p3) \
   : ((i) == 4) ? (void *)&((event)->uuppp.p4) \
   : NULL)

typedef struct {
  Word code;
  Word clock;
  Word w0;
  EventStringStruct s1;
} EventWSStruct;

#define EVENT_WS_FIELD_PTR(event, i) \
  (((i) == 0) ? (void *)&((event)->ws.w0) \
   : ((i) == 1) ? (void *)&((event)->ws.s1) \
   : NULL)


typedef union {
  Event0Struct any;
  EventAStruct a;
  EventAWStruct aw;
  EventPStruct p;
  EventPAAStruct paa;
  EventPAWStruct paw;
  EventPAWAStruct pawa;
  EventPDDWWWStruct pddwww;
  EventPPStruct pp;
  EventPPAUStruct ppau;
  EventPPAWPStruct ppawp;
  EventPPPStruct ppp;
  EventPPPAStruct pppa;
  EventPPPUStruct pppu;
  EventPPPUUStruct pppuu;
  EventPPUStruct ppu;
  EventPPUUStruct ppuu;
  EventPPUWWWStruct ppuwww;
  EventPPWWStruct ppww;
  EventPPWWWStruct ppwww;
  EventPPWWWUUUStruct ppwwwuuu;
  EventPUStruct pu;
  EventPWStruct pw;
  EventPWAStruct pwa;
  EventPWAWStruct pwaw;
  EventPWPStruct pwp;
  EventPWUStruct pwu;
  EventPWWStruct pww;
  EventPWWWWDDStruct pwwwwdd;
  EventPWWWWWStruct pwwwww;
  EventPWWWWWWWWWStruct pwwwwwwwww;
  EventPWWWWWWWWWWWWStruct pwwwwwwwwwwww;
  EventUUPAStruct uupa;
  EventUUPPStruct uupp;
  EventUUPPPStruct uuppp;
  EventWSStruct ws;
} EventUnion;


#define EVENT_0(type) \
  EVENT_BEGIN(type) \
  EVENT_END(type, 0, sizeof(Event0Struct))

#define EVENT_A(type, _a0) \
  EVENT_BEGIN(type) \
    EventMould.a.a0 = (_a0); \
  EVENT_END(type, A, sizeof(EventAStruct))

#define EVENT_AW(type, _a0, _w1) \
  EVENT_BEGIN(type) \
    EventMould.aw.a0 = (_a0); \
    EventMould.aw.w1 = (_w1); \
  EVENT_END(type, AW, sizeof(EventAWStruct))

#define EVENT_P(type, _p0) \
  EVENT_BEGIN(type) \
    EventMould.p.p0 = (_p0); \
  EVENT_END(type, P, sizeof(EventPStruct))

#define EVENT_PAA(type, _p0, _a1, _a2) \
  EVENT_BEGIN(type) \
    EventMould.paa.p0 = (_p0); \
    EventMould.paa.a1 = (_a1); \
    EventMould.paa.a2 = (_a2); \
  EVENT_END(type, PAA, sizeof(EventPAAStruct))

#define EVENT_PAW(type, _p0, _a1, _w2) \
  EVENT_BEGIN(type) \
    EventMould.paw.p0 = (_p0); \
    EventMould.paw.a1 = (_a1); \
    EventMould.paw.w2 = (_w2); \
  EVENT_END(type, PAW, sizeof(EventPAWStruct))

#define EVENT_PAWA(type, _p0, _a1, _w2, _a3) \
  EVENT_BEGIN(type) \
    EventMould.pawa.p0 = (_p0); \
    EventMould.pawa.a1 = (_a1); \
    EventMould.pawa.w2 = (_w2); \
    EventMould.pawa.a3 = (_a3); \
  EVENT_END(type, PAWA, sizeof(EventPAWAStruct))

#define EVENT_PDDWWW(type, _p0, _d1, _d2, _w3, _w4, _w5) \
  EVENT_BEGIN(type) \
    EventMould.pddwww.p0 = (_p0); \
    EventMould.pddwww.d1 = (_d1); \
    EventMould.pddwww.d2 = (_d2); \
    EventMould.pddwww.w3 = (_w3); \
    EventMould.pddwww.w4 = (_w4); \
    EventMould.pddwww.w5 = (_w5); \
  EVENT_END(type, PDDWWW, sizeof(EventPDDWWWStruct))

#define EVENT_PP(type, _p0, _p1) \
  EVENT_BEGIN(type) \
    EventMould.pp.p0 = (_p0); \
    EventMould.pp.p1 = (_p1); \
  EVENT_END(type, PP, sizeof(EventPPStruct))

#define EVENT_PPAU(type, _p0, _p1, _a2, _u3) \
  EVENT_BEGIN(type) \
    EventMould.ppau.p0 = (_p0); \
    EventMould.ppau.p1 = (_p1); \
    EventMould.ppau.a2 = (_a2); \
    EventMould.ppau.u3 = (_u3); \
  EVENT_END(type, PPAU, sizeof(EventPPAUStruct))

#define EVENT_PPAWP(type, _p0, _p1, _a2, _w3, _p4) \
  EVENT_BEGIN(type) \
    EventMould.ppawp.p0 = (_p0); \
    EventMould.ppawp.p1 = (_p1); \
    EventMould.ppawp.a2 = (_a2); \
    EventMould.ppawp.w3 = (_w3); \
    EventMould.ppawp.p4 = (_p4); \
  EVENT_END(type, PPAWP, sizeof(EventPPAWPStruct))

#define EVENT_PPP(type, _p0, _p1, _p2) \
  EVENT_BEGIN(type) \
    EventMould.ppp.p0 = (_p0); \
    EventMould.ppp.p1 = (_p1); \
    EventMould.ppp.p2 = (_p2); \
  EVENT_END(type, PPP, sizeof(EventPPPStruct))

#define EVENT_PPPA(type, _p0, _p1, _p2, _a3) \
  EVENT_BEGIN(type) \
    EventMould.pppa.p0 = (_p0); \
    EventMould.pppa.p1 = (_p1); \
    EventMould.pppa.p2 = (_p2); \
    EventMould.pppa.a3 = (_a3); \
  EVENT_END(type, PPPA, sizeof(EventPPPAStruct))

#define EVENT_PPPU(type, _p0, _p1, _p2, _u3) \
  EVENT_BEGIN(type) \
    EventMould.pppu.p0 = (_p0); \
    EventMould.pppu.p1 = (_p1); \
    EventMould.pppu.p2 = (_p2); \
    EventMould.pppu.u3 = (_u3); \
  EVENT_END(type, PPPU, sizeof(EventPPPUStruct))

#define EVENT_PPPUU(type, _p0, _p1, _p2, _u3, _u4) \
  EVENT_BEGIN(type) \
    EventMould.pppuu.p0 = (_p0); \
    EventMould.pppuu.p1 = (_p1); \
    EventMould.pppuu.p2 = (_p2); \
    EventMould.pppuu.u3 = (_u3); \
    EventMould.pppuu.u4 = (_u4); \
  EVENT_END(type, PPPUU, sizeof(EventPPPUUStruct))

#define EVENT_PPU(type, _p0, _p1, _u2) \
  EVENT_BEGIN(type) \
    EventMould.ppu.p0 = (_p0); \
    EventMould.ppu.p1 = (_p1); \
    EventMould.ppu.u2 = (_u2); \
  EVENT_END(type, PPU, sizeof(EventPPUStruct))

#define EVENT_PPUU(type, _p0, _p1, _u2, _u3) \
  EVENT_BEGIN(type) \
    EventMould.ppuu.p0 = (_p0); \
    EventMould.ppuu.p1 = (_p1); \
    EventMould.ppuu.u2 = (_u2); \
    EventMould.ppuu.u3 = (_u3); \
  EVENT_END(type, PPUU, sizeof(EventPPUUStruct))

#define EVENT_PPUWWW(type, _p0, _p1, _u2, _w3, _w4, _w5) \
  EVENT_BEGIN(type) \
    EventMould.ppuwww.p0 = (_p0); \
    EventMould.ppuwww.p1 = (_p1); \
    EventMould.ppuwww.u2 = (_u2); \
    EventMould.ppuwww.w3 = (_w3); \
    EventMould.ppuwww.w4 = (_w4); \
    EventMould.ppuwww.w5 = (_w5); \
  EVENT_END(type, PPUWWW, sizeof(EventPPUWWWStruct))

#define EVENT_PPWW(type, _p0, _p1, _w2, _w3) \
  EVENT_BEGIN(type) \
    EventMould.ppww.p0 = (_p0); \
    EventMould.ppww.p1 = (_p1); \
    EventMould.ppww.w2 = (_w2); \
    EventMould.ppww.w3 = (_w3); \
  EVENT_END(type, PPWW, sizeof(EventPPWWStruct))

#define EVENT_PPWWW(type, _p0, _p1, _w2, _w3, _w4) \
  EVENT_BEGIN(type) \
    EventMould.ppwww.p0 = (_p0); \
    EventMould.ppwww.p1 = (_p1); \
    EventMould.ppwww.w2 = (_w2); \
    EventMould.ppwww.w3 = (_w3); \
    EventMould.ppwww.w4 = (_w4); \
  EVENT_END(type, PPWWW, sizeof(EventPPWWWStruct))

#define EVENT_PPWWWUUU(type, _p0, _p1, _w2, _w3, _w4, _u5, _u6, _u7) \
  EVENT_BEGIN(type) \
    EventMould.ppwwwuuu.p0 = (_p0); \
    EventMould.ppwwwuuu.p1 = (_p1); \
    EventMould.ppwwwuuu.w2 = (_w2); \
    EventMould.ppwwwuuu.w3 = (_w3); \
    EventMould.ppwwwuuu.w4 = (_w4); \
    EventMould.ppwwwuuu.u5 = (_u5); \
    EventMould.ppwwwuuu.u6 = (_u6); \
    EventMould.ppwwwuuu.u7 = (_u7); \
  EVENT_END(type, PPWWWUUU, sizeof(EventPPWWWUUUStruct))

#define EVENT_PU(type, _p0, _u1) \
  EVENT_BEGIN(type) \
    EventMould.pu.p0 = (_p0); \
    EventMould.pu.u1 = (_u1); \
  EVENT_END(type, PU, sizeof(EventPUStruct))

#define EVENT_PW(type, _p0, _w1) \
  EVENT_BEGIN(type) \
    EventMould.pw.p0 = (_p0); \
    EventMould.pw.w1 = (_w1); \
  EVENT_END(type, PW, sizeof(EventPWStruct))

#define EVENT_PWA(type, _p0, _w1, _a2) \
  EVENT_BEGIN(type) \
    EventMould.pwa.p0 = (_p0); \
    EventMould.pwa.w1 = (_w1); \
    EventMould.pwa.a2 = (_a2); \
  EVENT_END(type, PWA, sizeof(EventPWAStruct))

#define EVENT_PWAW(type, _p0, _w1, _a2, _w3) \
  EVENT_BEGIN(type) \
    EventMould.pwaw.p0 = (_p0); \
    EventMould.pwaw.w1 = (_w1); \
    EventMould.pwaw.a2 = (_a2); \
    EventMould.pwaw.w3 = (_w3); \
  EVENT_END(type, PWAW, sizeof(EventPWAWStruct))

#define EVENT_PWP(type, _p0, _w1, _p2) \
  EVENT_BEGIN(type) \
    EventMould.pwp.p0 = (_p0); \
    EventMould.pwp.w1 = (_w1); \
    EventMould.pwp.p2 = (_p2); \
  EVENT_END(type, PWP, sizeof(EventPWPStruct))

#define EVENT_PWU(type, _p0, _w1, _u2) \
  EVENT_BEGIN(type) \
    EventMould.pwu.p0 = (_p0); \
    EventMould.pwu.w1 = (_w1); \
    EventMould.pwu.u2 = (_u2); \
  EVENT_END(type, PWU, sizeof(EventPWUStruct))

#define EVENT_PWW(type, _p0, _w1, _w2) \
  EVENT_BEGIN(type) \
    EventMould.pww.p0 = (_p0); \
    EventMould.pww.w1 = (_w1); \
    EventMould.pww.w2 = (_w2); \
  EVENT_END(type, PWW, sizeof(EventPWWStruct))

#define EVENT_PWWWWDD(type, _p0, _w1, _w2, _w3, _w4, _d5, _d6) \
  EVENT_BEGIN(type) \
    EventMould.pwwwwdd.p0 = (_p0); \
    EventMould.pwwwwdd.w1 = (_w1); \
    EventMould.pwwwwdd.w2 = (_w2); \
    EventMould.pwwwwdd.w3 = (_w3); \
    EventMould.pwwwwdd.w4 = (_w4); \
    EventMould.pwwwwdd.d5 = (_d5); \
    EventMould.pwwwwdd.d6 = (_d6); \
  EVENT_END(type, PWWWWDD, sizeof(EventPWWWWDDStruct))

#define EVENT_PWWWWW(type, _p0, _w1, _w2, _w3, _w4, _w5) \
  EVENT_BEGIN(type) \
    EventMould.pwwwww.p0 = (_p0); \
    EventMould.pwwwww.w1 = (_w1); \
    EventMould.pwwwww.w2 = (_w2); \
    EventMould.pwwwww.w3 = (_w3); \
    EventMould.pwwwww.w4 = (_w4); \
    EventMould.pwwwww.w5 = (_w5); \
  EVENT_END(type, PWWWWW, sizeof(EventPWWWWWStruct))

#define EVENT_PWWWWWWWWW(type, _p0, _w1, _w2, _w3, _w4, _w5, _w6, _w7, _w8, _w9) \
  EVENT_BEGIN(type) \
    EventMould.pwwwwwwwww.p0 = (_p0); \
    EventMould.pwwwwwwwww.w1 = (_w1); \
    EventMould.pwwwwwwwww.w2 = (_w2); \
    EventMould.pwwwwwwwww.w3 = (_w3); \
    EventMould.pwwwwwwwww.w4 = (_w4); \
    EventMould.pwwwwwwwww.w5 = (_w5); \
    EventMould.pwwwwwwwww.w6 = (_w6); \
    EventMould.pwwwwwwwww.w7 = (_w7); \
    EventMould.pwwwwwwwww.w8 = (_w8); \
    EventMould.pwwwwwwwww.w9 = (_w9); \
  EVENT_END(type, PWWWWWWWWW, sizeof(EventPWWWWWWWWWStruct))

#define EVENT_PWWWWWWWWWWWW(type, _p0, _w1, _w2, _w3, _w4, _w5, _w6, _w7, _w8, _w9, _w10, _w11, _w12) \
  EVENT_BEGIN(type) \
    EventMould.pwwwwwwwwwwww.p0 = (_p0); \
    EventMould.pwwwwwwwwwwww.w1 = (_w1); \
    EventMould.pwwwwwwwwwwww.w2 = (_w2); \
    EventMould.pwwwwwwwwwwww.w3 = (_w3); \
    EventMould.pwwwwwwwwwwww.w4 = (_w4); \
    EventMould.pwwwwwwwwwwww.w5 = (_w5); \
    EventMould.pwwwwwwwwwwww.w6 = (_w6); \
    EventMould.pwwwwwwwwwwww.w7 = (_w7); \
    EventMould.pwwwwwwwwwwww.w8 = (_w8); \
    EventMould.pwwwwwwwwwwww.w9 = (_w9); \
    EventMould.pwwwwwwwwwwww.w10 = (_w10); \
    EventMould.pwwwwwwwwwwww.w11 = (_w11); \
    EventMould.pwwwwwwwwwwww.w12 = (_w12); \
  EVENT_END(type, PWWWWWWWWWWWW, sizeof(EventPWWWWWWWWWWWWStruct))

#define EVENT_UUPA(type, _u0, _u1, _p2, _a3) \
  EVENT_BEGIN(type) \
    EventMould.uupa.u0 = (_u0); \
    EventMould.uupa.u1 = (_u1); \
    EventMould.uupa.p2 = (_p2); \
    EventMould.uupa.a3 = (_a3); \
  EVENT_END(type, UUPA, sizeof(EventUUPAStruct))

#define EVENT_UUPP(type, _u0, _u1, _p2, _p3) \
  EVENT_BEGIN(type) \
    EventMould.uupp.u0 = (_u0); \
    EventMould.uupp.u1 = (_u1); \
    EventMould.uupp.p2 = (_p2); \
    EventMould.uupp.p3 = (_p3); \
  EVENT_END(type, UUPP, sizeof(EventUUPPStruct))

#define EVENT_UUPPP(type, _u0, _u1, _p2, _p3, _p4) \
  EVENT_BEGIN(type) \
    EventMould.uuppp.u0 = (_u0); \
    EventMould.uuppp.u1 = (_u1); \
    EventMould.uuppp.p2 = (_p2); \
    EventMould.uuppp.p3 = (_p3); \
    EventMould.uuppp.p4 = (_p4); \
  EVENT_END(type, UUPPP, sizeof(EventUUPPPStruct))

#define EVENT_WS(type, _w0, _l1, _s1) \
  EVENT_BEGIN(type) \
    size_t _string_len; \
    EventMould.ws.w0 = (_w0); \
    _string_len = (_l1); \
    AVER(_string_len < EventStringLengthMAX); \
    EventMould.ws.s1.len = (EventStringLen)_string_len; \
    mps_lib_memcpy(EventMould.ws.s1.str, _s1, _string_len); \
  EVENT_END(type, WS, offsetof(EventWSStruct, s1.str) + _string_len)

#define EventFormat0 0
#define EventFormatA 1
#define EventFormatAW 2
#define EventFormatP 3
#define EventFormatPAA 4
#define EventFormatPAW 5
#define EventFormatPAWA 6
#define EventFormatPDDWWW 7
#define EventFormatPP 8
#define EventFormatPPAU 9
#define EventFormatPPAWP 10
#define EventFormatPPP 11
#define EventFormatPPPA 12
#define EventFormatPPPU 13
#define EventFormatPPPUU 14
#define EventFormatPPU 15
#define EventFormatPPUU 16
#define EventFormatPPUWWW 17
#define EventFormatPPWW 18
#define EventFormatPPWWW 19
#define EventFormatPPWWWUUU 20
#define EventFormatPU 21
#define EventFormatPW 22
#define EventFormatPWA 23
#define EventFormatPWAW 24
#define EventFormatPWP 25
#define EventFormatPWU 26
#define EventFormatPWW 27
#define EventFormatPWWWWDD 28
#define EventFormatPWWWWW 29
#define EventFormatPWWWWWWWWW 30
#define EventFormatPWWWWWWWWWWWW 31
#define EventFormatUUPA 32
#define EventFormatUUPP 33
#define EventFormatUUPPP 34
#define EventFormatWS 35

#else /* EVENT not */

#define EVENT_0(type) NOOP
#define EVENT_A(type, p0) NOOP
#define EVENT_AW(type, p0, p1) NOOP
#define EVENT_P(type, p0) NOOP
#define EVENT_PAA(type, p0, p1, p2) NOOP
#define EVENT_PAW(type, p0, p1, p2) NOOP
#define EVENT_PAWA(type, p0, p1, p2, p3) NOOP
#define EVENT_PDDWWW(type, p0, p1, p2, p3, p4, p5) NOOP
#define EVENT_PP(type, p0, p1) NOOP
#define EVENT_PPAU(type, p0, p1, p2, p3) NOOP
#define EVENT_PPAWP(type, p0, p1, p2, p3, p4) NOOP
#define EVENT_PPP(type, p0, p1, p2) NOOP
#define EVENT_PPPA(type, p0, p1, p2, p3) NOOP
#define EVENT_PPPU(type, p0, p1, p2, p3) NOOP
#define EVENT_PPPUU(type, p0, p1, p2, p3, p4) NOOP
#define EVENT_PPU(type, p0, p1, p2) NOOP
#define EVENT_PPUU(type, p0, p1, p2, p3) NOOP
#define EVENT_PPUWWW(type, p0, p1, p2, p3, p4, p5) NOOP
#define EVENT_PPWW(type, p0, p1, p2, p3) NOOP
#define EVENT_PPWWW(type, p0, p1, p2, p3, p4) NOOP
#define EVENT_PPWWWUUU(type, p0, p1, p2, p3, p4, p5, p6, p7) NOOP
#define EVENT_PU(type, p0, p1) NOOP
#define EVENT_PW(type, p0, p1) NOOP
#define EVENT_PWA(type, p0, p1, p2) NOOP
#define EVENT_PWAW(type, p0, p1, p2, p3) NOOP
#define EVENT_PWP(type, p0, p1, p2) NOOP
#define EVENT_PWU(type, p0, p1, p2) NOOP
#define EVENT_PWW(type, p0, p1, p2) NOOP
#define EVENT_PWWWWDD(type, p0, p1, p2, p3, p4, p5, p6) NOOP
#define EVENT_PWWWWW(type, p0, p1, p2, p3, p4, p5) NOOP
#define EVENT_PWWWWWWWWW(type, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) NOOP
#define EVENT_PWWWWWWWWWWWW(type, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) NOOP
#define EVENT_UUPA(type, p0, p1, p2, p3) NOOP
#define EVENT_UUPP(type, p0, p1, p2, p3) NOOP
#define EVENT_UUPPP(type, p0, p1, p2, p3, p4) NOOP
#define EVENT_WS(type, p0, p1, l1) NOOP

#endif /* EVENT */
