#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

BOOL LayoutMenuItems(struct MenuItem *firstitem, APTR vi, ...) {
  va_list ap;
  va_start(ap, vi);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return LayoutMenuItemsA(firstitem, vi, taglist);
}
