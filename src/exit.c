#include <stubs.h>
#include <clib/dos_protos.h>

#pragma amiga library dos

void _Stub_exit(int exitCode) __noreturn_function {
  Exit(exitCode);   // low level exit to Amiga
}
