;;; Startup variant, change attribute value if you make your own
              .rtmodel cstartup,"amiga"

              .rtmodel version, "1"

              ;; External declarations
              .section sstack
              .section stack
              .section data_init_table

              .extern __initialize_data, __initialize_udata
              .extern main, exit, __original_sp

#ifdef __CALYPSI_DATA_MODEL_SMALL__
              .extern _NearBaseAddress
#endif

#ifdef __CALYPSI_CODE_MODEL_SMALL__
#define call bsr.w
#define jump bra.w
#define libcode nearcode
#else
#define call jsr
#define jump jmp
#define libcode code
#endif

;;; **** Auto open Amiga library
autoOpen:     .macro  lib
              .section start, noroot, noreorder
              .pubweak __call_initialize_\lib
              .extern  __initialize_\lib
__call_initialize_\lib:
	      call    __initialize_\lib
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
	      call    __initialize_sections

#ifdef __CALYPSI_DATA_MODEL_SMALL__
	      move.l  sp,(.near __original_sp,a4)
#else
	      move.l  sp,__original_sp
#endif
;;; **** Auto open Amiga libraries
              autoOpen DOSLibrary
              autoOpen IntuitionLibrary
              autoOpen GfxLibrary

;;; **** Initialize streams if needed.
              .section start, noroot, noreorder
              .pubweak __call_initialize_global_streams
              .extern __initialize_global_streams
__call_initialize_global_streams:
              call     __initialize_global_streams

;;; **** Initialize heap if needed.
              .section start, noroot, noreorder
              .pubweak __call_heap_initialize
              .extern __heap_initialize, __default_heap
__call_heap_initialize:
	      call    __heap_chunk_size
#ifdef __CALYPSI_DATA_MODEL_SMALL__
	      lea     (.near __default_heap,a4),a0
#else
	      lea     __default_heap,a0
#endif
	      call    __heap_initialize

              .section start, root, noreorder
	      .extern __descriptor_list     ; initialize file descriptor list
#ifdef __CALYPSI_DATA_MODEL_SMALL__
	      lea     (.near __descriptor_list,a4),a0
#else
	      lea     __descriptor_list,a0
#endif
	      move.l   a0,8(a0)
	      addq.l   #4,a0
	      clr.l    (a0)
	      move.l   a0,-(a0)

              .section start, root, noreorder
	      .extern __argc, __argv , __arg_setup
	      call    __arg_setup   ; set up arguments for main()
#ifdef __CALYPSI_DATA_MODEL_SMALL__
	      move.l  (.near __argv,a4),a0
	      move.l  (.near __argc,a4),d0
#else
	      move.l  __argv,a0
	      move.l  __argc,d0
#endif
	      call    main
	      jump    exit

;;; Initial chunk size for the heap. If you know you use very little
;;; heap you add a function __heap_chunk_size that returns a smaller
;;; number. If you know you are going to use a lot of heap, you can
;;; instead start with a larger number.

	      .section libcode
	      .pubweak __heap_chunk_size
__heap_chunk_size:
	      move.l  #8192,d0
	      rts

	      .pubweak _Stub_exit
#ifdef __CALYPSI_DATA_MODEL_SMALL__
	      .section znear,bss
	      .public __original_sp
	      .align  2
__original_sp:
	      .space  4
	      .section libcode
_Stub_exit:
	      move.l  (.near __original_sp,a4),sp
	      rts
#else
	      .section zfar,bss
	      .public __original_sp
	      .align  2
__original_sp:
	      .space  4
	      .section code
_Stub_exit:
	      move.l  __original_sp,sp
	      rts
#endif
