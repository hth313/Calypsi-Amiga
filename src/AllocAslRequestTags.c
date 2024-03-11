#include <proto/asl.h>
#include <stdarg.h>

APTR AllocAslRequestTags(ULONG reqType, ...) {
  va_list ap;
  va_start(ap, reqType);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AllocAslRequest(reqType, taglist);
}
