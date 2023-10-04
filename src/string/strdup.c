#include <stdlib.h>
#include <string.h>

char *__strdup(const char *s)
{
	size_t l = strlen(s);
	char *d = malloc(l+1);
	if (!d) return NULL;
	return memcpy(d, s, l+1);
}

__attribute__ ((__weak__, alias("__strdup"))) char *strdup(const char *s);
__attribute__ ((alias("__strdup"))) char *__cheerp_strdup(const char *s);
