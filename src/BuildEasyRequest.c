#include <proto/intuition.h>
#include <stdarg.h>

struct Window *BuildEasyRequest(struct Window *window, CONST struct EasyStruct *easyStruct, ULONG idcmp, ...) {
  va_list ap;
  va_start(ap, idcmp);
  CONST_APTR taglist = va_arg(ap, CONST_APTR);
  va_end(ap);
  return BuildEasyRequestArgs(window, easyStruct, idcmp, taglist);
}
