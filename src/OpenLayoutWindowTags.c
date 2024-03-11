#include <clib/reaction_lib_protos.h>
#include <stdarg.h>

struct Window *OpenLayoutWindowTags(struct Gadget *layout, struct Screen *screen, ...) {
  va_list ap;
  va_start(ap, screen);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return OpenLayoutWindowTagList(layout, screen, taglist);
}
