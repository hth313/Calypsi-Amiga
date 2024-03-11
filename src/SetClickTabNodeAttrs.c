#include <proto/clicktab.h>
#include <stdarg.h>

VOID SetClickTabNodeAttrs(struct Node *node, ...) {
  va_list ap;
  va_start(ap, node);
  struct TagItem *taglist = va_arg(ap, struct TagItem *);
  va_end(ap);
  return SetClickTabNodeAttrsA(node, taglist);
}
