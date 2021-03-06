/************************************************************************\
**                                                                      **
**               OS/2(r) Physical Device Driver Libraries               **
**                         for Watcom C/C++ 10                          **
**                                                                      **
**  COPYRIGHT:                                                          **
**                                                                      **
**    (C)ACPSoft 1996                                                   **
**                                                                      **
**  DISCLAIMER OF WARRANTIES:                                           **
**                                                                      **
**    The following [enclosed] code is provided to you "AS IS",         **
**    without warranty of any kind.  You have a royalty-free right to   **
**    use, modify, reproduce and distribute the following code (and/or  **
**    any modified version) provided that you agree that Advanced       **
**    Gravis has no warranty obligations and shall not be liable for    **
**    any damages arising out of your use of this code, even if they    **
**    have been advised of the possibility of such damages.  This       **
**    Copyright statement and Disclaimer of Warranties may not be       **
**    removed.                                                          **
**                                                                      **
\************************************************************************/


//error.c
//
// error code
// Handle unsupported requests
//
// History:
//
// May 13, 96  Alger Pike    Initial version


#include <devhelp.h>
#include <devdebug.h>
#include <devtype.h>
#include <devrp.h>


#if defined(DEBUG)

static const char* MSG_ERROR         = "Watcom Sample Device Driver Remove";

#else

#define            MSG_ERROR         0

#endif // DEBUG

WORD16 StratError(RP FAR* _rp)
  {
  RPIOCtl FAR* rp = (RPIOCtl FAR*)_rp;
  // This command should shutdown any hardware devices that were setup
  // during the initialization stage.  Also, this command should free
  // any resources that the driver owns.
  // Print a message to the debug terminal saying when error
  cdbg << SKELETON;
  cdbg << MSG_ERROR << hex << setw(4);
  cdbg << setw() << setb() << endl;
  return RPDONE | RPERR_COMMAND;
  }
