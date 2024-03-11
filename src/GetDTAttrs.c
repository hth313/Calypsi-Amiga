#include <proto/datatypes.h>
#include <utility/tagitem.h>
#include <stdarg.h>

ULONG GetDTAttrs(Object *o, ...) {
  va_list ap;
  va_start(ap, o);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return GetDTAttrsA(o, taglist);
}
