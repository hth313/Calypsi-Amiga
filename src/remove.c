#include "io.h"
#include <calypsi/stubs.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <proto/dos.h>
#include <dos/dos.h>

int _Stub_remove(const char *path) {
  if (DeleteFile((STRPTR)path) == DOSTRUE) {
    return 0;
  } else {
    __set_errno(__translate_io_error_to_errno(IoErr()));
    return EOF;
  }
}
