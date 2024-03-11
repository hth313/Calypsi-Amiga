#include <proto/intuition.h>
#include <stdarg.h>

LONG EasyRequest(struct Window *window, CONST struct EasyStruct *easyStruct, ULONG *idcmpPtr, ...) {
  va_list ap;
  va_start(ap, idcmpPtr);
  CONST_APTR taglist = va_arg(ap, CONST_APTR);
  va_end(ap);
  return EasyRequestArgs(window, easyStruct, idcmpPtr, taglist);
}
