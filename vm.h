#ifndef _VM_VM_H
#define _VM_VM_H
#include "common.h"

struct vm {
   Class* stringClass;
   uint32_t allocatedBytes; 
   Parser* curParser;
};

void initVM(VM* vm);
VM* newVM(void);
#endif
