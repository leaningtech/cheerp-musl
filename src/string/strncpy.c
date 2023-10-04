#include <string.h>

char *__strncpy(char *restrict d, const char *restrict s, size_t n)
{
	__stpncpy(d, s, n);
	return d;
}
__attribute__ ((__weak__, alias("__strncpy"))) char *strncpy(char *restrict d, const char *restrict s, size_t n);
__attribute__ ((alias("__strncpy"))) char *__cheerp_strncpy(char *restrict d, const char *restrict s, size_t n);
