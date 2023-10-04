#include <string.h>

int __strncmp(const char *_l, const char *_r, size_t n)
{
	const unsigned char *l=(void *)_l, *r=(void *)_r;
	if (!n--) return 0;
	for (; *l && *r && n && *l == *r ; l++, r++, n--);
	return *l - *r;
}

__attribute__ ((__weak__, alias("__strncmp"))) int strncmp(const char *_l, const char *_r, size_t n);
__attribute__ ((alias("__strncmp"))) int __cheerp_strncmp(const char *_l, const char *_r, size_t n);
