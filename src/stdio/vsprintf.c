#include <stdio.h>
#include <limits.h>

int __vsprintf(char *restrict s, const char *restrict fmt, va_list ap)
{
	return vsnprintf(s, INT_MAX, fmt, ap);
}

__attribute__ ((__weak__, alias("__vsprintf"))) int vsprintf(char *restrict s, const char *restrict fmt, va_list ap);
__attribute__ ((alias("__vsprintf"))) int __cheerp_vsprintf(char *restrict s, const char *restrict fmt, va_list ap);
