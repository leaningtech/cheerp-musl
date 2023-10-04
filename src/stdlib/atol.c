#include <stdlib.h>
#include <ctype.h>

long __atol(const char *s)
{
	long n=0;
	int neg=0;
	while (isspace(*s)) s++;
	switch (*s) {
	case '-': neg=1;
	case '+': s++;
	}
	/* Compute n as a negative number to avoid overflow on LONG_MIN */
	while (isdigit(*s))
		n = 10*n - (*s++ - '0');
	return neg ? n : -n;
}

__attribute__ ((__weak__, alias("__atol"))) long atol(const char *s);
__attribute__ ((alias("__atol"))) long __cheerp_atol(const char *s);
