#include <stdlib.h>
#include <syscall.h>

void __cheerp_free(void* ptr);

void __unmapself(void *base, size_t size)
{
	// Take advantage of the fact that Wasm has a shadow stack
	// NOTE: This is somewhat risky, we have no guarantee that free
	//       will not use the linear memory stack
	__cheerp_free(base);
	__syscall(SYS_exit, 0);
}
