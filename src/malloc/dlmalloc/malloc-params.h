#define HAVE_MMAP 1
#define HAVE_MORECORE 0
#define UNSIGNED_MORECORE 1
#define MORECORE_CANNOT_TRIM 1

#define ABORT __builtin_unreachable()
#define NO_MALLOC_STATS 1
#define MALLINFO_FIELD_TYPE int

#define USE_LOCKS 0

#define MALLOC_ALIGNMENT (__alignof__(max_align_t))

#include <errno.h>
static inline void set_errno()
{
	errno = ENOMEM;
}
#define MALLOC_FAILURE_ACTION set_errno();
