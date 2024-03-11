#include <proto/wb.h>
#include <utility/tagitem.h>
#include <stdarg.h>

struct AppWindow *AddAppWindow(ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, ...) {
  va_list ap;
  va_start(ap, msgport);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AddAppWindowA(id, userdata, window, msgport, taglist);
}
