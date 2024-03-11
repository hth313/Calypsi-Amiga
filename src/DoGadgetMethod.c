#include <proto/intuition.h>
#include <stdarg.h>

ULONG DoGadgetMethod(struct Gadget *gad, struct Window *win, struct Requester *req, ...) {
  va_list ap;
  va_start(ap, req);
  Msg msg = va_arg(ap, Msg);
  va_end(ap);
  return DoGadgetMethodA(gad, win, req, msg);
}
