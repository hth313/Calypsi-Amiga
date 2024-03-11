#include <proto/datatypes.h>
#include <utility/tagitem.h>
#include <stdarg.h>

struct DataType *ObtainDataType(ULONG type, APTR handle, ...) {
  va_list ap;
  va_start(ap, handle);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return ObtainDataTypeA(type, handle, taglist);
}
