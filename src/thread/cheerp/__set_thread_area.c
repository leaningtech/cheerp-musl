#include "pthread_impl.h"

int __set_thread_area(void *p)
{
#if defined(__wasm__) && !defined(__CHEERP__)
	__clang_wasm_set_tls_base((uintptr_t)p - __clang_wasm_tls_size_aligned());
#elif defined(__CHEERP__) && defined(__ASMJS__)
	__builtin_cheerp_set_thread_pointer(p);
#endif
	return __syscall(SYS_set_thread_area, p);
}
