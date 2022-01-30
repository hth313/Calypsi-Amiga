// This module auto opens dos.library

#include <stdlib.h>
#include <clib/exec_protos.h>

#pragma require __call_initialize_DOSLibrary
#pragma amiga library exec

struct DosLibrary *DOSBase;

static void closeDosLibrary () {
  CloseLibrary((struct Library*)DOSBase);
}

void __initialize_DOSLibrary () {
  if ((DOSBase = (struct DosLibrary*)OpenLibrary((CONST_STRPTR)"dos.library", 0))) {
    atexit(closeDosLibrary);
  } else {
    exit(10);
  }
}
