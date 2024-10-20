#include "io.h"
#include <calypsi/stubs.h>
#include <errno.h>
#include <stdlib.h>
#include <proto/dos.h>
#include <dos/dos.h>
#include <exec/lists.h>

int _Stub_close(int fd) {
  int offset = OffsetToFirstFD;
  for (struct __io_descriptors *p =
           (struct __io_descriptors *)__descriptor_list.mlh_Head;
       p->node.mln_Succ != 0;
       p = (struct __io_descriptors *)p->node.mln_Succ,
	 offset += DescriptorsInRecord) {
    int i = fd - offset;
    if (i < DescriptorsInRecord) {
      if (p->desc[i]) {
        Close(p->desc[i]);
        p->desc[i] = 0;
        p->used -= 1;
	return 0;
      }
    }
  }
  // File does not exist
  return -ENOENT;
}
