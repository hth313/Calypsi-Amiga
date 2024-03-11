#include <proto/amigaguide.h>
#include <stdarg.h>

LONG SetAmigaGuideAttrs(APTR cl, ...) {
  va_list ap;
  va_start(ap, cl);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SetAmigaGuideAttrsA(cl, taglist);
}
