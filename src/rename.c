#include "io.h"
#include <calypsi/stubs.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <proto/dos.h>
#include <dos/dos.h>

int _Stub_rename(const char *oldpath, const char *newpath) {
  if (Rename((STRPTR)oldpath, (STRPTR)newpath) == DOSTRUE) {
    return 0;
  } else {
    return -(__translate_io_error_to_errno(IoErr()));
  }
}
