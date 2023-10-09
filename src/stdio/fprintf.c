#include <stdio.h>
#include <stdarg.h>

int __fprintf(FILE *restrict f, const char *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vfprintf(f, fmt, ap);
	va_end(ap);
	return ret;
}

__attribute__ ((__weak__, alias("__fprintf"))) int fprintf(FILE *restrict f, const char *restrict fmt, ...);
__attribute__ ((alias("__fprintf"))) int __cheerp_fprintf(FILE *restrict f, const char *restrict fmt, ...);
