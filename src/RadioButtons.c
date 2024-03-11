#include <clib/reaction_lib_protos.h>
#include <stdarg.h>

__attribute__((simple_call)) struct List *RadioButtons(STRPTR first_text, ...) {
  return RadioButtonsA((STRPTR*)&first_text);
}
