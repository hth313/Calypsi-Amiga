#include "io.h"
#include <calypsi/stubs.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <proto/dos.h>

size_t _Stub_write(int fd, const void *buf, size_t count) {
  BPTR handle = __get_file_handle(fd);
  if (handle) {
    long result = Write(handle, buf, count);
    if (result == -1) {
      return -(__translate_io_error_to_errno(IoErr()));
    }
    return result;
  } else {
    return -ENOENT;
  }
}
