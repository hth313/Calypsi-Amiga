#include <proto/amigaguide.h>
#include <stdarg.h>

LONG RemoveAmigaGuideHost(APTR hh, ...) {
  va_list ap;
  va_start(ap, hh);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return RemoveAmigaGuideHostA(hh, taglist);
}
