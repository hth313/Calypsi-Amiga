#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

struct Menu *CreateMenus(CONST struct NewMenu *newmenu, ...) {
  va_list ap;
  va_start(ap, newmenu);
  struct TagItem *taglist = va_arg(ap, struct TagItem *);
  va_end(ap);
  return CreateMenusA(newmenu, taglist);
}
