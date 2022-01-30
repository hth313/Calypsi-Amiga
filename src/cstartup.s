;;; Startup variant, change attribute value if you make your own
              .rtmodel cstartup,"amiga"

              .rtmodel version, "1"

              ;; External declarations
              .section sstack
              .section stack
              .section heap
              .section data_init_table

              .extern __initialize_data, __initialize_udata
              .extern main, exit

#ifdef __CALYPSI_DATA_MODEL_SMALL__
              .extern _NearBaseAddress
#endif

;;; **** Auto open Amiga library
autoOpen:     .macro  lib
              .section start, noroot, noreorder
              .pubweak __call_initialize_\lib
              .extern  __initialize_\lib
__call_initialize_\lib:
              jsr     __initialize_\lib
              .endm


              .section start, noroot, noreorder
              .public __program_root_section
              .public __program_start
              .align  2
__program_root_section:
__program_start:
#ifdef __CALYPSI_DATA_MODEL_SMALL__
              lea.l   _NearBaseAddress.l,a4
#endif
;;; Initialize data sections if needed.
              .section start, noroot, noreorder
              .pubweak __data_initialization_needed
              .extern __initialize_sections
__data_initialization_needed:
              move.l  #(.sectionStart data_init_table),a0
              move.l  #(.sectionEnd data_init_table),a1
              jsr     __initialize_sections

;;; **** Auto open Amiga libraries
              autoOpen DOSLibrary
              autoOpen IntuitionLibrary
              autoOpen GfxLibrary

;;; **** Initialize streams if needed.
              .section start, noroot, noreorder
              .pubweak __call_initialize_global_streams
              .extern __initialize_global_streams
__call_initialize_global_streams:
              jsr     __initialize_global_streams

;;; **** Initialize heap if needed.
              .section start, noroot, noreorder
              .pubweak __call_heap_initialize
              .extern __heap_initialize, __default_heap
__call_heap_initialize:
              move.l  #.sectionSize heap,d0
              move.l  #__default_heap,a0
              move.l  #.sectionStart heap,a1
              jsr     __heap_initialize

              .section start, root, noreorder
              moveq.l #0,d0         ; argc = 0
              jsr     main
              jmp     exit
