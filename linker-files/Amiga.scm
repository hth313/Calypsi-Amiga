;;; This is a placeholder that gives a fictive memory for the Amiga to
;;; make the Calypsi linker happy, for now.

(define memories
  '((memory flash (address (#x100000 . #x1fffff))
            (section (start #x100000)
                     (nearcode (#x100000 . #x10a000))
                     code inear ifar cfar switch data_init_table))
    (memory NearRAM (address (#x200000 . #x20ffff))
            (section znear near))
    (memory RAM (address (#x210000 . #x23ffff))
            (section sstack stack zfar far heap))
    (memory Vector (address (#x0000 . #x03ff))
            (section (reset #x0000)))
    (block stack (size #x2000))
    (base-address _NearBaseAddress NearRAM #x8000)
    ))
