#define INTERNAL_MUSL
#include <stdlib.h>
#include <errno.h>

#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
weak
int posix_memalign(void **res, size_t align, size_t len)
{
	if (align < sizeof(void *)) return EINVAL;
	void *mem = aligned_alloc(align, len);
	if (!mem) return errno;
	*res = mem;
	return 0;
}
