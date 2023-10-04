#include <stdio.h>
#include <stdarg.h>

int __printf(const char *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vfprintf(stdout, fmt, ap);
	va_end(ap);
	return ret;
}

__attribute__ ((__weak__, alias("__printf"))) int printf(const char *restrict fmt, ...);
__attribute__ ((alias("__printf"))) int __cheerp_printf(const char *restrict fmt, ...);
