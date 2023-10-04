#include <stdio.h>

int __vprintf(const char *restrict fmt, va_list ap)
{
	return vfprintf(stdout, fmt, ap);
}

__attribute__ ((__weak__, alias("__vprintf"))) int vprintf(const char *restrict fmt, va_list ap);
__attribute__ ((alias("__vprintf"))) int __cheerp_vprintf(const char *restrict fmt, va_list ap);
