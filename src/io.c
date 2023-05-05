#include <errno.h>
#include <dos/dos.h>
#include <exec/lists.h>
#include <exec/nodes.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <calypsi/stubs.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

#define DescriptorsInRecord 32

struct __io_descriptors {
  struct MinNode node;
  int used;
  BPTR desc[DescriptorsInRecord];
};

struct MinList __descriptor_list;

int _Stub_open(const char *path, int oflag, ...) {
  int desc = -1;
  int offset = 3;
  BPTR *storage;
  struct __io_descriptors *node;
  for (struct __io_descriptors *p =
           (struct __io_descriptors *)__descriptor_list.mlh_Head;
       p != 0 && desc < 0;
       p = (struct __io_descriptors *)p->node.mln_Succ, offset += DescriptorsInRecord) {
    if (p->used < DescriptorsInRecord) {
      for (int i = 0;; i++) {
        if (p->desc[i] == 0) {
          desc = offset + i;
          storage = &p->desc[i];
	  node = p;
          break;
        }
      }
    }
  }
  if (desc < 0) {
    // Ran out of descriptors, need a new record.
    node = (struct __io_descriptors *) malloc(sizeof(struct __io_descriptors));
    if (node == 0) {
      __set_errno(ENOMEM);
      return EOF;
    }
    memset(node, 0, sizeof(struct __io_descriptors));
    AddTail((struct List *)&__descriptor_list, (struct Node*) &node->node);
    desc = offset;
    storage = &node->desc[0];
  }
  int mode = MODE_OLDFILE;
  if ((oflag & O_CREAT)) {
    mode = MODE_NEWFILE;
  }

  BPTR handle = Open((CONST_STRPTR)path, mode);
  if (handle == 0) {
    __set_errno(__translate_io_error_to_errno(IoErr()));
    return EOF;
  }
  *storage = handle;
  node-> used += 1;
  return desc;
}

int _Stub_close(int fd) {
  int offset = 3;
  BPTR fdesc;
  for (struct __io_descriptors *p =
           (struct __io_descriptors *)__descriptor_list.mlh_Head;
       p != 0;
       p = (struct __io_descriptors *)p->node.mln_Succ,
	 offset += DescriptorsInRecord) {
    int i = fd - offset;
    if (i + DescriptorsInRecord) {
      if (p->desc[i]) {
        Close(p->desc[i]);
        p->desc[i] = 0;
        p->used -= 1;
	return 0;
      } else {
	break;
      }
    }
  }
  // File does not exist
  __set_errno(ENOENT);
  return -1;
}
