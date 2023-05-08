#include <calypsi/stubs.h>
#include <stdio.h>

int _Stub_fsetpos(int fd, const fpos_t *pos) {
  if (_Stub_lseek(fd, *pos, SEEK_SET) != EOF) {
    return 0;
  } else {
    return EOF;
  }
}
