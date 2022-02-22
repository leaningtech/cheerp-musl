#define _BSD_SOURCE
#include <stdlib.h>

typedef int (*cmpfun)(const void *, const void *);

struct wrapper_ptr
{
	cmpfun f;
};
static int wrapper_cmp(const void *v1, const void *v2, void *cmp)
{
	return ((struct wrapper_ptr*)cmp)->f(v1, v2);
}

void qsort(void *base, size_t nel, size_t width, cmpfun cmp)
{
	struct wrapper_ptr w = { cmp };
	__qsort_r(base, nel, width, wrapper_cmp, &w);
}
