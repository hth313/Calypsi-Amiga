#ifndef __AMIGA_IO_H
#define __AMIGA_IO_H

extern int __translate_io_error_to_errno(LONG io_err);
extern int __translate_access_io_error_to_errno(LONG io_err);

#endif // __AMIGA_IO_H
