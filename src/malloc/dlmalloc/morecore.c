#if !defined(__CHEERP__) || defined(__ASMJS__)
#include <sys/mman.h>
#include "syscall.h"
#include "malloc-params.h"

#ifndef __CHEERP__
char* volatile _heapStart;
#endif

// This function has the semantics of sbrk
void* dlmalloc_morecore(int size)
{
	static char* end = 0;
	if (!end)
	{
		// Use the compiler-provided heapStart if valid, otherwise
		// resort to the syscall, which might might be less precise
		if (_heapStart != 0)
			end = _heapStart;
		else
			end = (char*)SYS_brk(0);
	}
	char* ret = (char*)SYS_brk(end+size);
	if (ret < end + size)
		return (char*)-1;
	char* base = end;
	end += size;
	return base;
}

// The host may honor MAP_UNINITIALIZED and skip zero-filling; dlmalloc is
// built with MMAP_CLEARS 0 so calloc never relies on mapped memory being zero
void* dlmalloc_mmap(size_t size)
{
	return __mmap(0, size, PROT_READ|PROT_WRITE,
	              MAP_PRIVATE|MAP_ANONYMOUS|MAP_UNINITIALIZED, -1, 0);
}

int dlmalloc_munmap(void* addr, size_t size)
{
	return __munmap(addr, size);
}
#endif
