#include <proto/chooser.h>
#include <utility/tagitem.h>
#include <stdarg.h>

VOID SetChooserNodeAttrs(struct Node *node, ...) {
  va_list ap;
  va_start(ap, node);
  struct TagItem *taglist = va_arg(ap, struct TagItem *);
  va_end(ap);
  return SetChooserNodeAttrsA(node, taglist);
}
