#include <proto/dos.h>
#include <utility/tagitem.h>
#include <stdarg.h>

LONG SystemTags(CONST_STRPTR command, ...) {
  va_list ap;
  va_start(ap, command);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SystemTagList(command, taglist);
}
