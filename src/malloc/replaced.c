#include "dynlink.h"

#ifdef __CHEERP__
__attribute((cheerp_asmjs))
#endif
int __malloc_replaced;
#ifdef __CHEERP__
__attribute((cheerp_asmjs))
#endif
int __aligned_alloc_replaced;
