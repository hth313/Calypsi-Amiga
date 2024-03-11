#include <proto/graphics.h>
#include <utility/tagitem.h>
#include <stdarg.h>

WORD WeighTAMatchTags(CONST struct TextAttr *reqTextAttr, CONST struct TextAttr *targetTextAttr, ...) {
  va_list ap;
  va_start(ap, targetTextAttr);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return WeighTAMatch(reqTextAttr, targetTextAttr, taglist);
}
