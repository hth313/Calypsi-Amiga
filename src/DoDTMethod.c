#include <proto/datatypes.h>
#include <utility/tagitem.h>
#include <stdarg.h>

ULONG DoDTMethod(Object *o, struct Window *win, struct Requester *req, ...) {
  va_list ap;
  va_start(ap, req);
  Msg msg = va_arg(ap, Msg);
  va_end(ap);
  return DoDTMethodA(o, win, req, msg);
}
