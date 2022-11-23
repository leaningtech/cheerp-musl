#define _BSD_SOURCE
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include "syscall.h"

#ifdef __CHEERP__
__attribute__((cheerp_wasm))
#endif
void *sbrk(intptr_t inc)
{
	if (inc) return (void *)__syscall_ret(-ENOMEM);
	return (void *)__syscall(SYS_brk, 0);
}
