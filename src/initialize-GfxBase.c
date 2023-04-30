// This module auto opens graphics.library

#include <stdlib.h>
#include <proto/exec.h>
#include <proto/graphics.h>

#pragma require __call_initialize_GfxLibrary
#pragma amiga library exec

struct GfxBase * GfxBase;

static void closeGfxLibrary () {
  CloseLibrary((struct Library*)GfxBase);
}

void __initialize_GfxLibrary () {
  if ((GfxBase = (struct GfxBase*)OpenLibrary((CONST_STRPTR)"graphics.library", 0))) {
    atexit(closeGfxLibrary);
  } else {
    exit(10);
  }
}
