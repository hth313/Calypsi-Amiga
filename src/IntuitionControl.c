#include <proto/intuition.h>
#include <stdarg.h>

ULONG IntuitionControl(APTR object, ...) {
  va_list ap;
  va_start(ap, object);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return IntuitionControlA(object, taglist);
}
