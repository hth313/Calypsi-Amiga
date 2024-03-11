#include <proto/wb.h>
#include <utility/tagitem.h>
#include <stdarg.h>

struct AppWindowDropZone *AddAppWindowDropZone(struct AppWindow *aw, ULONG id, ULONG userdata, ...) {
  va_list ap;
  va_start(ap, userdata);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return AddAppWindowDropZoneA(aw, id, userdata, taglist);
}
