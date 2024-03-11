#include <proto/datatypes.h>
#include <utility/tagitem.h>
#include <stdarg.h>

VOID RefreshDTObject(Object *o, struct Window *win, struct Requester *req, ...) {
  va_list ap;
  va_start(ap, req);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return RefreshDTObjectA(o, win, req, taglist);
}
