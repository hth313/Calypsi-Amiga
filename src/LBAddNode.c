#include <clib/reaction_lib_protos.h>
#include <stdarg.h>

struct Node *LBAddNode(struct Gadget *gad, struct Window *win, struct Requester *req, struct Node *node, ...) {
  va_list ap;
  va_start(ap, node);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return LBAddNodeA(gad, win, req, node, taglist);
}
