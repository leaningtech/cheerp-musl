#include <string.h>

char *__strchr(const char *s, int c)
{
	char *r = __strchrnul(s, c);
	return *(unsigned char *)r == (unsigned char)c ? r : 0;
}
__attribute__ ((__weak__, alias("__strchr"))) char *strchr(const char *s, int c);
__attribute__ ((alias("__strchr"))) char *__cheerp__strchr(const char *s, int c);
