#include <proto/dos.h>
#include <utility/tagitem.h>
#include <stdarg.h>

LONG FPrintf(BPTR fh, CONST_STRPTR format, ...) {
  va_list ap;
  va_start(ap, format);
  CONST_APTR array = va_arg(ap, CONST_APTR);
  va_end(ap);
  return VFPrintf(fh, format, array);
}
