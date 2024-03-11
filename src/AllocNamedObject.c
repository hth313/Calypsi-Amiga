#include <proto/utility.h>
#include <stdarg.h>

struct NamedObject *AllocNamedObject(CONST_STRPTR name, ...) {
  va_list ap;
  va_start(ap, name);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AllocNamedObjectA(name, taglist);
}
