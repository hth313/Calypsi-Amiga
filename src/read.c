#include "io.h"
#include <calypsi/stubs.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <proto/dos.h>

size_t _Stub_read(int fd, void *buf, size_t count) {
  BPTR handle = __get_file_handle(fd);
  if (handle) {
    long result = Read(handle, buf, count);
    if (result == -1) {
      __set_errno(__translate_io_error_to_errno(IoErr()));
    }
    return result;
  } else {
    __set_errno(ENOENT);
    return EOF;
  }
}
