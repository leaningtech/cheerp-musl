#define _BSD_SOURCE
#define INTERNAL_MUSL
#include <errno.h>
#include <stdlib.h>

void *reallocarray(void *ptr, size_t m, size_t n)
{
#if defined(__CHEERP__) && !defined(__ASMJS__)
	return 0;
#else
	if (n && m > -1 / n) {
		errno = ENOMEM;
		return 0;
	}

	return realloc(ptr, m * n);
#endif
}
