#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

APTR GetVisualInfo( struct Screen *screen, ... ) {
  va_list ap;
  va_start(ap, screen);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return GetVisualInfoA(screen, taglist);
}
