#define _BSD_SOURCE
#include <string.h>

#if ! (defined(__CHEERP__) && !defined(__ASMJS__))
void explicit_bzero(void *d, size_t n)
{
	d = memset(d, 0, n);
//	__asm__ __volatile__ ("" : : "r"(d) : "memory");
}
#endif
