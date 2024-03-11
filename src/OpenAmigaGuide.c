#include <proto/amigaguide.h>
#include <stdarg.h>

APTR OpenAmigaGuide(struct NewAmigaGuide *nag, ...) {
  va_list ap;
  va_start(ap, nag);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return OpenAmigaGuideA(nag, taglist);
}
