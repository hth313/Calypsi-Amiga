#include <clib/reaction_lib_protos.h>
#include <stdarg.h>

__attribute__((simple_call)) struct List *ClickTabs(STRPTR first_text, ...) {
  return ClickTabsA((STRPTR*)&first_text);
}
