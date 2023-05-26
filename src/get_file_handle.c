#include "io.h"
#include <proto/dos.h>

BPTR __get_file_handle(int fd) {
  if (fd < 3) {
    if (fd == 0) {
      return Input();
    } else if (fd == 1) {
      return Output();
    } else {
      return ErrorOutput();
    }
  } else {
    int offset = 3;
    BPTR fdesc;
    for (struct __io_descriptors *p =
           (struct __io_descriptors *)__descriptor_list.mlh_Head;
	 p != 0;
	 p = (struct __io_descriptors *)p->node.mln_Succ,
	 offset += DescriptorsInRecord) {
      int i = fd - offset;
      if (i < DescriptorsInRecord) {
	return p->desc[i];
      }
    }
  }
  // File does not exist
  return 0;
}
