#include <proto/graphics.h>
#include <utility/tagitem.h>
#include <stdarg.h>

LONG ObtainBestPen(struct ColorMap *cm, ULONG r, ULONG g, ULONG b, ...) {
  va_list ap;
  va_start(ap, b);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return ObtainBestPenA(cm, r, g, b, taglist);
}
