#include <proto/datatypes.h>
#include <utility/tagitem.h>
#include <stdarg.h>

ULONG SetDTAttrs(Object *o, struct Window *win, struct Requester *req, ...) {
  va_list ap;
  va_start(ap, req);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SetDTAttrsA(o, win, req, taglist);
}
