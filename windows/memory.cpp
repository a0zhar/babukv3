#include "Memory.h"

static HANDLE proc_heap = 0;

void _hfree(void *mem) {
	HeapFree(proc_heap, 0, mem);
}

void _mem_initialize() {
	proc_heap = GetProcessHeap();
}

void *_halloc(SIZE_T count) {
retry:;
	LPVOID ret = HeapAlloc(proc_heap, HEAP_ZERO_MEMORY, count + 64);
	if (ret == 0) goto retry;
	return ret;
}