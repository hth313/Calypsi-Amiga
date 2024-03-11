#include <proto/graphics.h>
#include <utility/tagitem.h>
#include <stdarg.h>

ULONG ExtendFontTags(struct TextFont *font, ...) {
  va_list ap;
  va_start(ap, font);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return ExtendFont(font, taglist);
}
