#include <proto/wb.h>
#include <utility/tagitem.h>
#include <stdarg.h>

BOOL ChangeWorkbenchSelection(CONST_STRPTR name, struct Hook *hook, ...) {
  va_list ap;
  va_start(ap, hook);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return ChangeWorkbenchSelectionA(name, hook, taglist);
}
