#include <stdio.h>
#include <stdarg.h>

int __sprintf(char *restrict s, const char *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vsprintf(s, fmt, ap);
	va_end(ap);
	return ret;
}

__attribute__ ((__weak__, alias("__sprintf"))) int sprintf(char *restrict s, const char *restrict fmt, ...);
__attribute__ ((alias("__sprintf"))) int __cheerp_sprintf(char *restrict s, const char *restrict fmt, ...);
