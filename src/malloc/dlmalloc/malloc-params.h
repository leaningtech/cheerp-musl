#define HAVE_MMAP 0
#define HAVE_MORECORE 1
#define MORECORE_CONTIGUOUS 1
#define MORECORE_CANNOT_TRIM 1
#define malloc_getpagesize (64*1024)
#define DEFAULT_GRANULARITY malloc_getpagesize

#include "syscall.h"

__attribute__((cheerp_wasm))
static inline void* __sbrk(int size)
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
#define MORECORE __sbrk

#define ABORT __builtin_unreachable()
#define NO_MALLOC_STATS 1
#define MALLINFO_FIELD_TYPE int

#define USE_LOCKS 0

#define MALLOC_ALIGNMENT 8

#include <errno.h>
static inline void set_errno()
{
	errno = ENOMEM;
}
#define MALLOC_FAILURE_ACTION set_errno();
