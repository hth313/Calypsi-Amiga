#include <proto/bullet.h>
#include <stdarg.h>

ULONG ObtainInfo(struct GlyphEngine *glyphEngine, ...) {
  va_list ap;
  va_start(ap, glyphEngine);
  CONST struct TagItem *taglist = va_arg(ap, CONST struct TagItem *);
  va_end(ap);
  return ObtainInfoA(glyphEngine, taglist);
}
