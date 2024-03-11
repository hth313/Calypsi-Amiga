#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

VOID GT_SetGadgetAttrs(struct Gadget *gad, struct Window *win, struct Requester *req, ...) {
  va_list ap;
  va_start(ap, req);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return GT_SetGadgetAttrsA(gad, win, req, taglist);
}
