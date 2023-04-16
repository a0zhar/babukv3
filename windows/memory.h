#ifndef __MEMORY_H
#define __MEMORY_H
#include <windows.h>

void _mem_initialize();

#define _memset memset
#define _memcpy memcpy

void* _halloc(SIZE_T count);
void _hfree(void* mem);

#endif
