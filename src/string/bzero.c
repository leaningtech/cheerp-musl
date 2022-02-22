#define _BSD_SOURCE
#include <string.h>
#include <strings.h>

#if ! (defined(__CHEERP__) && !defined(__ASMJS__))
void bzero(void *s, size_t n)
{
	memset(s, 0, n);
}
#endif
