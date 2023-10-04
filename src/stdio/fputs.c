#include "stdio_impl.h"
#include <string.h>

int __fputs(const char *restrict s, FILE *restrict f)
{
	size_t l = strlen(s);
	return (fwrite(s, 1, l, f)==l) - 1;
}

__attribute__ ((__weak__, alias("__fputs"))) int fputs(const char *restrict s, FILE *restrict f);
__attribute__ ((alias("__fputs"))) int __cheerp_fputs(const char *restrict s, FILE *restrict f);

weak_alias(fputs, fputs_unlocked);
