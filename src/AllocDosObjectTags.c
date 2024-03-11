#include <proto/dos.h>
#include <utility/tagitem.h>
#include <stdarg.h>

APTR AllocDosObjectTags(ULONG type, ...) {
  va_list ap;
  va_start(ap, type);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AllocDosObjectTagList(type, taglist);
}
