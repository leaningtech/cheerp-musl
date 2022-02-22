#include <stdlib.h>

#ifdef __CHEERP__
__attribute((cheerp_asmjs))
#endif
void *realloc(void *p, size_t n)
{
	return __libc_realloc(p, n);
}
