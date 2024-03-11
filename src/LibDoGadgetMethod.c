#include <clib/reaction_lib_protos.h>
#include <stdarg.h>

ULONG LibDoGadgetMethod(struct Gadget *gadget, struct Window *window, struct Requester *requester, ...) {
  va_list ap;
  va_start(ap, requester);
  Msg msg = va_arg(ap, Msg);
  va_end(ap);
  return LibDoGadgetMethodA(gadget, window, requester, msg);
}
