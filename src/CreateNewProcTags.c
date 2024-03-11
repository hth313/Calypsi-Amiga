#include <proto/dos.h>
#include <stdarg.h>

__attribute__((simple_call)) struct Process *CreateNewProcTags(ULONG firstTag, ...) {
  return CreateNewProcTagList((struct TagItem*)&firstTag);
}
