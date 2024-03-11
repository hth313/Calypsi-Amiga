#include <proto/asl.h>
#include <utility/tagitem.h>
#include <stdarg.h>

BOOL AslRequestTags(APTR requester, ...) {
  va_list ap;
  va_start(ap, requester);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AslRequest(requester, taglist);
}
