/*  impl.c.protlii3: PROTECTION FOR LINUX (Intel 386)
 *
 *  $HopeName: $
 *  Copyright (C) 1995,1999 Harlequin Group, all rights reserved
 *
 */


#include "prmcli.h"

#ifndef MPS_OS_LI
#error "protlii3.c is Linux specific, but MPS_OS_LI is not set"
#endif
#ifndef MPS_ARCH_I3
#error "protlii3.c is i386 specific, but MPS_ARCH_I3 is not set"
#endif
#ifndef PROTECTION
#error "protlii3.c implements protection, but PROTECTION is not set"
#endif

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <signal.h>

SRCID(protlii3, "$HopeName: $");

/* Useful stuff that doesn't appear to be in any header files. */

/*
 * Bits in err field of sigcontext for interrupt 14 (page fault)
 */

#define INT14_ERR_PAGEPROT   0x1
#define INT14_ERR_WRITE      0x2
#define INT14_ERR_USERMODE   0x4

/* The previously-installed signal action, as returned by */
/* sigaction(3).  See ProtSetup. */

static struct sigaction sigNext;

typedef void (*__real_lii3_sighandler_t) (int, struct sigcontext);


/* sigHandle -- protection signal handler
 *
 *  This is the signal handler installed by ProtSetup to deal with
 *  protection faults.  It is installed on the SIGSEGV signal.
 *  It decodes the protection fault details from the signal context
 *  and passes them to ArenaAccess, which attempts to handle the
 *  fault and remove its cause.  If the fault is handled, then
 *  the handler returns and execution resumes.  If it isn't handled,
 *  then sigHandle does its best to pass the signal on to the
 *  previously installed signal handler (sigNext).
 *
 *  .sigh.args: There is no officially documented way of getting the
 *  sigcontext, but on x86 Linux at least it is passed BY VALUE as a second
 *  argument to the signal handler.  The prototype doesn't include this arg.
 *
 *  .sigh.context: We only know how to handler interrupt 14, where context.err
 *  gives the page fault error code and context.cr2 gives the fault address.
 *  @@ The details of this should be checked somewhere (kernel sources?).
 *
 *  .sigh.addr: We assume that the OS decodes the address to something
 *  sensible
 */
 
static void sigHandle(int sig, struct sigcontext context)  /* .sigh.args */
{
  AVER(sig == SIGSEGV);

  if(context.trapno == 14) {  /* .sigh.context */
    AccessSet mode;
    Addr base, limit;
    MutatorFaultContextStruct mfContext;

    mfContext.scp = &context;

    mode = ((context.err & INT14_ERR_WRITE) != 0)  /* .sigh.context */
             ? (AccessREAD | AccessWRITE)
             : AccessREAD;

    /* We assume that the access is for one word at the address. */
    base = (Addr)context.cr2;   /* .sigh.addr */
    limit = AddrAdd(base, (Size)sizeof(Addr));

    /* Offer each protection structure the opportunity to handle the */
    /* exception.  If it succeeds, then allow the mutator to continue. */

    if(ArenaAccess(base, mode, &mfContext))
      return;
  }

  /* The exception was not handled by any known protection structure, */
  /* so throw it to the previously installed handler. */

  /* @@ This is really weak.
   * Need to implement rest of the contract of sigaction
   * We might want to set SA_RESETHAND in the flags and explicitly reinstall
   * the handler from withint itself so the SIG_DFL/SIG_IGN case can work
   * properly by just returning. */
  switch ((int)sigNext.sa_handler) {
  case (int)SIG_DFL:
  case (int)SIG_IGN:
  default:
    (*(__real_lii3_sighandler_t)sigNext.sa_handler)(sig, context);
    break;
  }
}


/*  ProtSetup -- global protection setup
 *
 *  Under Linux, the global setup involves installing a signal handler
 *  on SIGSEGV to catch and handle page faults (see sigHandle).
 *  The previous handler is recorded so that it can be reached from
 *  sigHandle if it fails to handle the fault.
 *
 *  NOTE: There are problems with this approach:
 *    1. we can't honor the sa_flags for the previous handler,
 *    2. what if this thread is suspended just after calling signal(3)?
 *       The sigNext variable will never be initialized!
 */

void ProtSetup(void)
{
  struct sigaction sa;
  int result;

  sa.sa_handler = (__sighandler_t)sigHandle;  /* .sigh.args */
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  result = sigaction(SIGSEGV, &sa, &sigNext);
  AVER(result == 0);
}

