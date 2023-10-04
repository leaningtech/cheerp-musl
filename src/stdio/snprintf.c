#include <stdio.h>
#include <stdarg.h>

int __snprintf(char *restrict s, size_t n, const char *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vsnprintf(s, n, fmt, ap);
	va_end(ap);
	return ret;
}


__attribute__ ((__weak__, alias("__snprintf"))) int snprintf(char *restrict s, size_t n, const char *restrict fmt, ...);
__attribute__ ((alias("__snprintf"))) int __cheerp_snprintf(char *restrict s, size_t n, const char *restrict fmt, ...);
