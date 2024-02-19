#define _BSD_SOURCE
#define INTERNAL_MUSL
#include <stdlib.h>

weak
void *memalign(size_t align, size_t len)
{
	return aligned_alloc(align, len);
}
