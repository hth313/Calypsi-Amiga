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
  struct LocalVar *var =
    FindVar((STRPTR)name, GVF_GLOBAL_ONLY | GVF_LOCAL_ONLY);
  if (var != 0) {
    return (char *)var->lv_Value;
  } else {
    return 0;
  }
}
