#include <proto/wb.h>
#include <utility/tagitem.h>
#include <stdarg.h>

BOOL WorkbenchControl(CONST_STRPTR name, ...) {
  va_list ap;
  va_start(ap, name);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return WorkbenchControlA(name, taglist);
}
