// This module auto opens intuition.library

#include <stdlib.h>
#include <clib/exec_protos.h>
#include <clib/graphics_protos.h>

#pragma require __call_initialize_GfxLibrary
#pragma amiga library exec

struct IntutionLibrary *IntutionBase;

static void closeGfxLibrary () {
  CloseLibrary((struct Library*)IntutionBase);
}

void __initialize_IntutionLibray () {
  if ((IntutionBase = (struct IntutionLibrary*)OpenLibrary((CONST_STRPTR)"intution.library", 0))) {
    atexit(closeGfxLibrary);
  } else {
    exit(10);
  }
}
