#include "io.h"
#include <errno.h>
#include <stdlib.h>
#include <proto/dos.h>
#include <dos/dos.h>
#include <dos/var.h>

// On the Amiga we make use of environment functions
// provided by AmigaOS, there is no need to implement
// _Stub_environ() function.
char *getenv(const char *name) {
  static char env_var_buffer[FILENAME_MAX];
  if (GetVar((STRPTR)name, (STRPTR)env_var_buffer, sizeof(env_var_buffer), 0) < 0) {
    __set_errno(__translate_io_error_to_errno(IoErr()));
    return 0;
  } else {
    return env_var_buffer;
  }
}
