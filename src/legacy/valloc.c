#define _BSD_SOURCE
#include <stdlib.h>
#include "libc.h"

#ifdef __CHEERP__
__attribute((cheerp_asmjs))
#endif
weak
void *valloc(size_t size)
{
	return memalign(PAGE_SIZE, size);
}
