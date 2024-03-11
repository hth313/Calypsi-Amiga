#include <proto/utility.h>
#include <stdarg.h>

LONG SNPrintf(STRPTR buffer, ULONG bufsize, CONST_STRPTR fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  CONST_APTR array = va_arg(ap, CONST_APTR);
  va_end(ap);
  return VSNPrintf(buffer, bufsize, fmt, array);
}
