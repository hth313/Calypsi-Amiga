VPATH = src

CFLAGS = -I /home/hth/Documents/Amiga/NDK3.2/Include_H --fd /home/hth/Documents/Amiga/NDK3.2/FD

# Library products
ALL_LIBS = Amiga-68000-sc-sd.a Amiga-68000-lc-sd.a \
           Amiga-68000-sc-ld.a Amiga-68000-lc-ld.a \
           Amiga-68000-sc-fod.a Amiga-68000-lc-fod.a \
           Amiga-68000-sc-sd-double64.a Amiga-68000-lc-sd-double64.a \
           Amiga-68000-sc-ld-double64.a Amiga-68000-lc-ld-double64.a \
           Amiga-68000-sc-fod-double64.a Amiga-68000-lc-fod-double64.a

# Common source files
ASM_SRCS = cstartup.s
C_SRCS = initialize-DOSBase.c initialize-IntuitionBase.c initialize-GfxBase.c \
         exit.c

# Object files
OBJS_68000_SC_SD = $(ASM_SRCS:%.s=%-68000-sc-sd.o) $(C_SRCS:%.c=%-68000-sc-sd.o)
OBJS_68000_LC_SD = $(ASM_SRCS:%.s=%-68000-lc-sd.o) $(C_SRCS:%.c=%-68000-lc-sd.o)

OBJS_68000_SC_LD = $(ASM_SRCS:%.s=%-68000-sc-ld.o) $(C_SRCS:%.c=%-68000-sc-ld.o)
OBJS_68000_LC_LD = $(ASM_SRCS:%.s=%-68000-lc-ld.o) $(C_SRCS:%.c=%-68000-lc-ld.o)

OBJS_68000_SC_FOD = $(ASM_SRCS:%.s=%-68000-sc-fod.o) $(C_SRCS:%.c=%-68000-sc-fod.o)
OBJS_68000_LC_FOD = $(ASM_SRCS:%.s=%-68000-lc-fod.o) $(C_SRCS:%.c=%-68000-lc-fod.o)

OBJS_68000_SC_SD_DOUBLE64 = $(ASM_SRCS:%.s=%-68000-sc-sd-double64.o) $(C_SRCS:%.c=%-68000-sc-sd-double64.o)
OBJS_68000_LC_SD_DOUBLE64 = $(ASM_SRCS:%.s=%-68000-lc-sd-double64.o) $(C_SRCS:%.c=%-68000-lc-sd-double64.o)

OBJS_68000_SC_LD_DOUBLE64 = $(ASM_SRCS:%.s=%-68000-sc-ld-double64.o) $(C_SRCS:%.c=%-68000-sc-ld-double64.o)
OBJS_68000_LC_LD_DOUBLE64 = $(ASM_SRCS:%.s=%-68000-lc-ld-double64.o) $(C_SRCS:%.c=%-68000-lc-ld-double64.o)

OBJS_68000_SC_FOD_DOUBLE64 = $(ASM_SRCS:%.s=%-68000-sc-fod-double64.o) $(C_SRCS:%.c=%-68000-sc-fod-double64.o)
OBJS_68000_LC_FOD_DOUBLE64 = $(ASM_SRCS:%.s=%-68000-lc-fod-double64.o) $(C_SRCS:%.c=%-68000-lc-fod-double64.o)

%-68000-sc-sd.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=small --data-model=small --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-sd.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=small --data-model=small --debug $(CFLAGS) --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-sd.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=large --data-model=small --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-sd.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=large --data-model=small --debug $(CFLAGS) --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-ld.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=small --data-model=large --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-ld.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=small --data-model=large --debug $(CFLAGS) --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-ld.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=large --data-model=large --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-ld.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=large --data-model=large --debug $(CFLAGS) --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-fod.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=small --data-model=far-only --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-fod.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=small --data-model=far-only --debug $(CFLAGS) --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-fod.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=large --data-model=far-only --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-fod.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=large --data-model=far-only --debug $(CFLAGS) --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-sd-double64.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=small --data-model=small --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-sd-double64.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=small --data-model=small --debug $(CFLAGS) --64bit-doubles --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-sd-double64.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=large --data-model=small --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-sd-double64.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=large --data-model=small --debug $(CFLAGS) --64bit-doubles --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-ld-double64.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=small --data-model=large --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-ld-double64.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=small --data-model=large --debug $(CFLAGS) --64bit-doubles --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-ld-double64.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=large --data-model=large --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-ld-double64.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=large --data-model=large --debug $(CFLAGS) --64bit-doubles --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-fod-double64.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=small --data-model=far-only --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-sc-fod-double64.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=small --data-model=far-only --debug $(CFLAGS) --64bit-doubles --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-fod-double64.o: %.s
	as68k --debug --core=68000 --target=Amiga --code-model=large --data-model=far-only --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%-68000-lc-fod-double64.o: %.c
	cc68k --core=68000 --target=Amiga --code-model=large --data-model=far-only --debug $(CFLAGS) --64bit-doubles --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<


all: $(ALL_LIBS)

Amiga-68000-sc-sd.a: $(OBJS_68000_SC_SD)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-lc-sd.a: $(OBJS_68000_LC_SD)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-sc-ld.a: $(OBJS_68000_SC_LD)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-lc-ld.a: $(OBJS_68000_LC_LD)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-sc-fod.a: $(OBJS_68000_SC_FOD)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-lc-fod.a: $(OBJS_68000_LC_FOD)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-sc-sd-double64.a: $(OBJS_68000_SC_SD_DOUBLE64)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-lc-sd-double64.a: $(OBJS_68000_LC_SD_DOUBLE64)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-sc-ld-double64.a: $(OBJS_68000_SC_LD_DOUBLE64)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-lc-ld-double64.a: $(OBJS_68000_LC_LD_DOUBLE64)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-sc-fod-double64.a: $(OBJS_68000_SC_FOD_DOUBLE64)
	(cd obj ; nlib ../$@ $^)

Amiga-68000-lc-fod-double64.a: $(OBJS_68000_LC_FOD_DOUBLE64)
	(cd obj ; nlib ../$@ $^)


clean:
	-(cd obj ; rm $(OBJS_SC_SD) $(OBJS_SC_SD:%.o=%.lst))
	-(cd obj ; rm $(OBJS_LC_SD) $(OBJS_LC_SD:%.o=%.lst))
	-(cd obj ; rm $(OBJS_SC_LD) $(OBJS_SC_LD:%.o=%.lst))
	-(cd obj ; rm $(OBJS_LC_LD) $(OBJS_LC_LD:%.o=%.lst))
	-(cd obj ; rm $(OBJS_SC_FOD) $(OBJS_SC_FOD:%.o=%.lst))
	-(cd obj ; rm $(OBJS_LC_FOD) $(OBJS_LC_FOD:%.o=%.lst))
	-(cd obj ; rm $(OBJS_SC_SD_DOUBLE64) $(OBJS_SC_SD_DOUBLE64:%.o=%.lst))
	-(cd obj ; rm $(OBJS_LC_SD_DOUBLE64) $(OBJS_LC_SD_DOUBLE64:%.o=%.lst))
	-(cd obj ; rm $(OBJS_SC_LD_DOUBLE64) $(OBJS_SC_LD_DOUBLE64:%.o=%.lst))
	-(cd obj ; rm $(OBJS_LC_LD_DOUBLE64) $(OBJS_LC_LD_DOUBLE64:%.o=%.lst))
	-(cd obj ; rm $(OBJS_SC_FOD_DOUBLE64) $(OBJS_SC_FOD_DOUBLE64:%.o=%.lst))
	-(cd obj ; rm $(OBJS_LC_FOD_DOUBLE64) $(OBJS_LC_FOD_DOUBLE64:%.o=%.lst))
	-rm $(ALL_LIBS)
