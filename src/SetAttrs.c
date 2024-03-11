#include <proto/intuition.h>
#include <stdarg.h>

ULONG SetAttrs(APTR object, ...) {
  va_list ap;
  va_start(ap, object);
  struct TagItem *taglist = va_arg(ap, struct TagItem *);
  va_end(ap);
  return SetAttrsA(object, taglist);
}
