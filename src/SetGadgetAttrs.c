#include <proto/intuition.h>
#include <stdarg.h>

ULONG SetGadgetAttrs(struct Gadget *gadget, struct Window *window, struct Requester *requester, ...) {
  va_list ap;
  va_start(ap, requester);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SetGadgetAttrsA(gadget, window, requester, taglist);
}
