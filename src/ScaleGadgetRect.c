#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

LONG ScaleGadgetRect(struct NewGadget *ng, ...) {
  va_list ap;
  va_start(ap, ng);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return ScaleGadgetRectA(ng, taglist);
}
