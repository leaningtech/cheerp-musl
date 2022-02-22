#define _GNU_SOURCE
#include <string.h>

#if ! (defined(__CHEERP__) && !defined(__ASMJS__))
void *mempcpy(void *dest, const void *src, size_t n)
{
	return (char *)memcpy(dest, src, n) + n;
}
#endif
