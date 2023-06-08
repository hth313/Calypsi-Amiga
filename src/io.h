#ifndef __AMIGA_IO_H
#define __AMIGA_IO_H

#include <dos/dos.h>
#include <exec/lists.h>

#define DescriptorsInRecord 32
#define OffsetToFirstFD     3

struct __io_descriptors {
  struct MinNode node;
  int used;
  BPTR desc[DescriptorsInRecord];
};

extern struct MinList __descriptor_list;

extern int __translate_io_error_to_errno(LONG io_err);
extern int __translate_access_io_error_to_errno(LONG io_err);
extern BPTR __get_file_handle(int fd);

#endif // __AMIGA_IO_H
