#include <proto/intuition.h>
#include <stdarg.h>

struct Window *OpenWindowTags(CONST struct NewWindow *newWindow, ...) {
  va_list ap;
  va_start(ap, newWindow);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return OpenWindowTagList(newWindow, taglist);
}
