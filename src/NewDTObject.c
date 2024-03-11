#include <proto/datatypes.h>
#include <utility/tagitem.h>
#include <stdarg.h>

Object *NewDTObject( CONST_STRPTR name, ... ) {
  va_list ap;
  va_start(ap, name);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return NewDTObjectA(name, taglist);
}
