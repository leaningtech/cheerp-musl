#define _GNU_SOURCE
#include <string.h>

char *__strcasestr(const char *h, const char *n)
{
	size_t l = strlen(n);
	for (; *h; h++) if (!strncasecmp(h, n, l)) return (char *)h;
	return 0;
}

__attribute__ ((__weak__, alias("__strcasestr"))) char *strcasestr(const char *h, const char *n);
__attribute__ ((alias("__strcasestr"))) char *__cheerp_strcasestr(const char *h, const char *n);
