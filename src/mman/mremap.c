#define _GNU_SOURCE
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdint.h>
#include "syscall.h"

static void dummy(void) { }
weak_alias(dummy, __vm_wait);

void *__mremap(void *old_addr, size_t old_len, size_t new_len, int flags)
{
	if (new_len >= PTRDIFF_MAX) {
		errno = ENOMEM;
		return MAP_FAILED;
	}

	return (void *)__syscall(SYS_mremap, old_addr, old_len, new_len, flags);
}

weak_alias(__mremap, mremap);
