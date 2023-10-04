#include <string.h>

char *__strncat(char *restrict d, const char *restrict s, size_t n)
{
	char *a = d;
	d += strlen(d);
	while (n && *s) n--, *d++ = *s++;
	*d++ = 0;
	return a;
}

__attribute__ ((__weak__, alias("__strncat"))) char *strncat(char *restrict d, const char *restrict s, size_t n);
__attribute__ ((alias("__strncat"))) char *__cheerp_strncat(char *restrict d, const char *restrict s, size_t n);
