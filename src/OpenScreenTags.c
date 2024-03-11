#include <proto/intuition.h>
#include <stdarg.h>

struct Screen *OpenScreenTags(CONST struct NewScreen *newScreen, ...) {
  va_list ap;
  va_start(ap, newScreen);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return OpenScreenTagList(newScreen, taglist);
}
