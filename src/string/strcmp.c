#include <string.h>

int __strcmp(const char *l, const char *r)
{
	for (; *l==*r && *l; l++, r++);
	return *(unsigned char *)l - *(unsigned char *)r;
}

__attribute__ ((__weak__, alias("__strcmp"))) int strcmp(const char *l, const char *r);
__attribute__ ((alias("__strcmp"))) int __cheerp_strcmp(const char *l, const char *r);
