#include <stdlib.h>
#include <wchar.h>

size_t __mbstowcs(wchar_t *restrict ws, const char *restrict s, size_t wn)
{
	return mbsrtowcs(ws, (void*)&s, wn, 0);
}

__attribute__ ((__weak__, alias("__mbstowcs"))) size_t mbstowcs(wchar_t *restrict ws, const char *restrict s, size_t wn);
__attribute__ ((alias("__mbstowcs"))) size_t __cheerp_mbstowcs(wchar_t *restrict ws, const char *restrict s, size_t wn);
