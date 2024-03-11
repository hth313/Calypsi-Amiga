#include <proto/amigaguide.h>
#include <stdarg.h>

LONG SetAmigaGuideContext(APTR cl, ULONG id, ...) {
  va_list ap;
  va_start(ap, id);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SetAmigaGuideContextA(cl, id, taglist);
}
