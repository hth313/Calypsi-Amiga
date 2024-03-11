#include <clib/reaction_lib_protos.h>
#include <stdarg.h>

__attribute__((simple_call)) struct List *BrowserNodes(STRPTR first_text, ...) {
  return BrowserNodesA((STRPTR*)&first_text);
}
