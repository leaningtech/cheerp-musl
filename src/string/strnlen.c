#include <string.h>

size_t __strnlen(const char *s, size_t n)
{
	const char *p = memchr(s, 0, n);
	return p ? p-s : n;
}
__attribute__ ((__weak__, alias("__strnlen"))) size_t strnlen(const char *s, size_t n);
__attribute__ ((alias("__strnlen"))) size_t __cheerp_strnlen(const char *s, size_t n);
