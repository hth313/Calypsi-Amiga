#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

BOOL LayoutMenus(struct Menu *firstmenu, APTR vi, ...) {
  va_list ap;
  va_start(ap, vi);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return LayoutMenusA(firstmenu, vi, taglist);
}
