// This module auto opens intuition.library

#include <stdlib.h>
#include <proto/exec.h>
#include <proto/intuition.h>

#pragma require __call_initialize_IntuitionLibrary
#pragma amiga library exec

struct IntutionLibrary *IntutionBase;

static void closeIntuitionLibrary () {
  CloseLibrary((struct Library*)IntutionBase);
}

void __initialize_IntutionLibrary () {
  if ((IntutionBase = (struct IntutionLibrary*)OpenLibrary((CONST_STRPTR)"intution.library", 0))) {
    atexit(closeIntuitionLibrary);
  } else {
    exit(10);
  }
}
