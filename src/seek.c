#include "io.h"
#include <calypsi/stubs.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <proto/dos.h>
#include <dos/dos.h>


long _Stub_lseek(int fd, long offset, int whence) {
  BPTR handle = __get_file_handle(fd);
  if (handle) {
    if (whence == OFFSET_BEGINNING)
      whence = SEEK_SET;
    else if (whence == OFFSET_CURRENT)
      whence = SEEK_CUR;
    else if (whence == OFFSET_END)
      whence = SEEK_END;
    else {
      return -EINVAL;
    }
    long result = Seek(handle, offset, whence);
    if (result == -1) {
      return -(__translate_io_error_to_errno(IoErr()));
    }
    return result;
  } else {
    return -ENOENT;
  }
}
