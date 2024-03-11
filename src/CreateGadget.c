#include <proto/gadtools.h>
#include <utility/tagitem.h>
#include <stdarg.h>

struct Gadget *CreateGadget(ULONG kind, struct Gadget *gad, struct NewGadget *ng, ...) {
  va_list ap;
  va_start(ap, ng);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return CreateGadgetA(kind, gad, ng, taglist);
}
