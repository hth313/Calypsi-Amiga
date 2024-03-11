#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

LONG GT_GetGadgetAttrs(struct Gadget *gad, struct Window *win, struct Requester *req, ...) {
  va_list ap;
  va_start(ap, req);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return GT_GetGadgetAttrsA(gad, win, req, taglist);
}
