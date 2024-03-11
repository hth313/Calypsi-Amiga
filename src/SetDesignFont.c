#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

LONG SetDesignFont(APTR vi, struct TextAttr *tattr, ...) {
  va_list ap;
  va_start(ap, tattr);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SetDesignFontA(vi, tattr, taglist);
}
