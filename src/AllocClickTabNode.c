#include <proto/clicktab.h>
#include <stdarg.h>

__attribute__((simple_call)) struct Node *AllocClickTabNode(Tag firstTag, ...) {
  return AllocClickTabNodeA((struct TagItem*)&firstTag);
}
