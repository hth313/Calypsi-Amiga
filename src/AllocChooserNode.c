#include <proto/chooser.h>
#include <stdarg.h>

__attribute__((simple_call)) struct Node *AllocChooserNode(Tag firstTag, ... ) {
  return AllocChooserNodeA((struct TagItem*)&firstTag);
}
