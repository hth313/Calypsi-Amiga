#include <proto/graphics.h>
#include <stdarg.h>

__attribute__((simple_call)) ULONG BestModeID(ULONG firstTag, ...) {
  return BestModeIDA((struct TagItem*)&firstTag);
}
