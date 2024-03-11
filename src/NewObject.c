#include <proto/intuition.h>
#include <stdarg.h>

APTR NewObject(struct IClass *classPtr, CONST_STRPTR classID, ...) {
  va_list ap;
  va_start(ap, classID);
  struct TagItem *taglist = va_arg(ap, struct TagItem *);
  va_end(ap);
  return NewObjectA(classPtr, classID, taglist);
}
