#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

VOID DrawBevelBox(struct RastPort *rport, LONG left, LONG top, LONG width, LONG height, ...) {
  va_list ap;
  va_start(ap, height);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return DrawBevelBoxA(rport, left, top, width, height, taglist);
}
