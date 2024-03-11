#include <proto/dos.h>
#include <utility/tagitem.h>
#include <stdarg.h>

APTR DoShellMethod(ULONG method, ...) {
  va_list ap;
  va_start(ap, method);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return DoShellMethodTagList(method, taglist);
}
