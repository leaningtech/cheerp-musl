#include <string.h>
#include <stdint.h>
#include <limits.h>

#define ALIGN (sizeof(size_t))
#define ONES ((size_t)-1/UCHAR_MAX)
#define HIGHS (ONES * (UCHAR_MAX/2+1))
#define HASZERO(x) ((x)-ONES & ~(x) & HIGHS)

size_t __strlen(const char *s)
{
	const char *a = s;
#if defined(__GNUC__) && !(defined(__CHEERP__) && !defined(__ASMJS__))
	typedef size_t __attribute__((__may_alias__)) word;
	const word *w;
	for (; (uintptr_t)s % ALIGN; s++) if (!*s) return s-a;
	for (w = (const void *)s; !HASZERO(*w); w++);
	s = (const void *)w;
#endif
	for (; *s; s++);
	return s-a;
}

__attribute__ ((__weak__, alias("__strlen"))) size_t strlen(const char *s);
__attribute__ ((alias("__strlen"))) size_t __cheerp_strlen(const char *s);
