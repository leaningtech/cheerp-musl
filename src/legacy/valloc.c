#define _BSD_SOURCE
#include <stdlib.h>
#include "libc.h"

weak void *valloc(size_t size)
{
	return memalign(PAGE_SIZE, size);
}
