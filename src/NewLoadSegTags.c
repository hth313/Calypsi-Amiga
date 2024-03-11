#include <proto/dos.h>
#include <utility/tagitem.h>
#include <stdarg.h>

BPTR NewLoadSegTags(CONST_STRPTR file, ...) {
  va_list ap;
  va_start(ap, file);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return NewLoadSegTagList(file, taglist);
}
