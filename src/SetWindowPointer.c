#include <proto/intuition.h>
#include <stdarg.h>

VOID SetWindowPointer(struct Window *win, ...) {
  va_list ap;
  va_start(ap, win);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SetWindowPointerA(win, taglist);
}
