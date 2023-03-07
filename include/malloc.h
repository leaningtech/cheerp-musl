#ifndef _MALLOC_H
#define _MALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_size_t

#include <bits/alltypes.h>

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);
#ifdef __CHEERP__
__attribute((cheerp_asmjs))
#endif
void *valloc (size_t);
#ifdef __CHEERP__
__attribute((cheerp_asmjs))
#endif
void *memalign(size_t, size_t);

size_t malloc_usable_size(void *);

#ifdef __cplusplus
}
#endif

#endif
