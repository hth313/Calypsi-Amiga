#include <proto/datatypes.h>
#include <utility/tagitem.h>
#include <stdarg.h>

ULONG PrintDTObject(Object *o, struct Window *w, struct Requester *r, ...) {
  va_list ap;
  va_start(ap, r);
  struct dtPrint * msg = va_arg(ap, struct dtPrint *);
  va_end(ap);
  return PrintDTObjectA(o, w, r, msg);
}
