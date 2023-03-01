#include "syscall.h"
#include "malloc-params.h"

// This function has the semantics of sbrk
#ifdef __CHEERP__
__attribute__((cheerp_wasm))
#endif
void* dlmalloc_morecore(int size)
{
	static char* end = 0;
	if (!end)
	{
		end = (char*)SYS_brk(0);
	}
	char* ret = (char*)SYS_brk(end+size);
	if (ret < end + size)
		return (char*)-1;
	char* base = end;
	end += size;
	return base;
}
