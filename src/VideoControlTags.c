#include <proto/graphics.h>
#include <utility/tagitem.h>
#include <stdarg.h>

BOOL VideoControlTags(struct ColorMap *colorMap, ...) {
  va_list ap;
  va_start(ap, colorMap);
  struct TagItem *taglist = va_arg(ap, struct TagItem *);
  va_end(ap);
  return VideoControl(colorMap, taglist);
}
