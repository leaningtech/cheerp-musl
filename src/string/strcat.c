#include <string.h>

char *__strcat(char *restrict dest, const char *restrict src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}

__attribute__ ((__weak__, alias("__strcat"))) char *strcat(char *restrict dest, const char *restrict src);
__attribute__ ((alias("__strcat"))) char *__cheerp_strcat(char *restrict dest, const char *restrict src);
