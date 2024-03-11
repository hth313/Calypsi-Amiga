#include <proto/graphics.h>
#include <utility/tagitem.h>
#include <stdarg.h>

LONG ChangeExtSprite(struct ViewPort *vp, struct ExtSprite *oldsprite, struct ExtSprite *newsprite, ...) {
  va_list ap;
  va_start(ap, newsprite);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return ChangeExtSpriteA(vp, oldsprite, newsprite, taglist);
}
