#define _BSD_SOURCE
#include <stdlib.h>

#ifdef __CHEERP__
__attribute((cheerp_asmjs))
#endif
weak
void *memalign(size_t align, size_t len)
{
	return aligned_alloc(align, len);
}
