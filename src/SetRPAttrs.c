#include <proto/graphics.h>
#include <utility/tagitem.h>
#include <stdarg.h>

VOID SetRPAttrs(struct RastPort *rp, ...) {
  va_list ap;
  va_start(ap, rp);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SetRPAttrsA(rp, taglist);
}
