#include <proto/wb.h>
#include <utility/tagitem.h>
#include <stdarg.h>

ULONG WhichWorkbenchObject(struct Window *window, LONG x, LONG y, ...) {
  va_list ap;
  va_start(ap, y);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return WhichWorkbenchObjectA(window, x, y, taglist);
}
