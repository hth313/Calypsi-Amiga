#include <clib/reaction_lib_protos.h>
#include <stdarg.h>

ULONG GetAttrs(Object *o, ...) {
  va_list ap;
  va_start(ap, o);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return GetAttrsA(o, taglist);
}
