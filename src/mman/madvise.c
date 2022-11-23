#include <sys/mman.h>
#include "syscall.h"

#ifdef __CHEERP__
__attribute((cheerp_wasm))
#endif
int __madvise(void *addr, size_t len, int advice)
{

	return __syscall(SYS_madvise, addr, len, advice);
}

weak_alias(__madvise, madvise);
