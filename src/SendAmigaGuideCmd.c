#include <proto/amigaguide.h>
#include <stdarg.h>

LONG SendAmigaGuideCmd(APTR cl, CONST_STRPTR cmd, ...) {
  va_list ap;
  va_start(ap, cmd);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return SendAmigaGuideCmdA(cl, (STRPTR) cmd, taglist);
}
