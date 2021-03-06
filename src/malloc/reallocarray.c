#define _BSD_SOURCE
#define INTERNAL_MUSL
#include <errno.h>
#include <stdlib.h>

#ifdef __CHEERP__
__attribute((cheerp_asmjs))
#endif
void *reallocarray(void *ptr, size_t m, size_t n)
{
	if (n && m > -1 / n) {
		errno = ENOMEM;
		return 0;
	}

	return realloc(ptr, m * n);
}
