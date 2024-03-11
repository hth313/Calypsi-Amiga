#include <proto/graphics.h>
#include <utility/tagitem.h>
#include <stdarg.h>

struct ExtSprite *AllocSpriteData(CONST struct BitMap *bm, ...) {
  va_list ap;
  va_start(ap, bm);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AllocSpriteDataA(bm, taglist);
}
