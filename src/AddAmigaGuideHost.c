#include <proto/amigaguide.h>
#include <stdarg.h>

APTR AddAmigaGuideHost(struct Hook *h, CONST_STRPTR name, ...) {
  va_list ap;
  va_start(ap, name);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AddAmigaGuideHostA(h, name, taglist);
}
