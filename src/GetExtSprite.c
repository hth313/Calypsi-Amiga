#include <proto/graphics.h>
#include <utility/tagitem.h>
#include <stdarg.h>

LONG GetExtSprite(struct ExtSprite *ss, ...) {
  va_list ap;
  va_start(ap, ss);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return GetExtSpriteA(ss, taglist);
}
