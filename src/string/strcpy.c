#include <string.h>

char *__strcpy(char *restrict dest, const char *restrict src)
{
	__stpcpy(dest, src);
	return dest;
}

__attribute__ ((__weak__, alias("__strcpy"))) char *strcpy(char *restrict dest, const char *restrict src);
__attribute__ ((alias("__strcpy"))) char *__cheerp_strcpy(char *restrict dest, const char *restrict src);
