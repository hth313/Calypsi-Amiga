#include <proto/wb.h>
#include <utility/tagitem.h>
#include <stdarg.h>

struct AppMenuItem *AddAppMenuItem(ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, ...) {
  va_list ap;
  va_start(ap, msgport);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AddAppMenuItemA(id, userdata, text, msgport, taglist);
}
