#include <proto/dos.h>
#include <utility/tagitem.h>
#include <stdarg.h>

VOID FWritef(BPTR fh, CONST_STRPTR format, ...) {
  va_list ap;
  va_start(ap, format);
  LONG *array = va_arg(ap, LONG *);
  va_end(ap);
  return VFWritef(fh, format, array);
}
