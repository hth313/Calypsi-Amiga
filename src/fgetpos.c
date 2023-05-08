#include <calypsi/stubs.h>
#include <stdio.h>

int _Stub_fgetpos(int fd, fpos_t *pos) {
  long result = _Stub_lseek(fd, 0, SEEK_SET);
  if (result == EOF) {
    return EOF;
  } else {
    *pos = result;
    return 0;
  }
}
