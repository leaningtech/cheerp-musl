#define HAVE_MMAP 0
#define HAVE_MORECORE 1
#define MORECORE_CONTIGUOUS 1
#define MORECORE_CANNOT_TRIM 1
#define malloc_getpagesize (64*1024)
#define DEFAULT_GRANULARITY malloc_getpagesize
#define USE_DL_PREFIX 1

#ifdef __CHEERP__
__attribute__((cheerp_wasm))
#endif
void* dlmalloc_morecore(int size);
#define MORECORE dlmalloc_morecore

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
