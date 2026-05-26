#ifndef __CHEERP_PTHREAD_ARCH_H
#define __CHEERP_PTHREAD_ARCH_H

#if defined(__wasm__) && !defined(__CHEERP__)
#include <stdint.h>

__attribute__((__visibility__("hidden"))) uintptr_t __clang_wasm_tls_base(void);
__attribute__((__visibility__("hidden"))) void __clang_wasm_set_tls_base(uintptr_t);
__attribute__((__visibility__("hidden"))) uintptr_t __clang_wasm_tls_size(void);
__attribute__((__visibility__("hidden"))) uintptr_t __clang_wasm_tls_align(void);

static inline uintptr_t __clang_wasm_tls_size_aligned()
{
	uintptr_t size = __clang_wasm_tls_size();
	uintptr_t align = __clang_wasm_tls_align();
	if (align > 1)
		size = (size + align - 1) & -align;
	return size;
}
#endif

struct __pthread; 
extern struct __pthread __dummy_thread;
static inline struct __pthread* __get_tp()
{
#if defined(__wasm__) && !defined(__CHEERP__)
	uintptr_t tls_base = __clang_wasm_tls_base();
	if (!tls_base)
		return &__dummy_thread;
	return (struct __pthread*)(tls_base + __clang_wasm_tls_size_aligned());
#elif defined(__ASMJS__)
	struct __pthread* ret = (struct __pthread*)__builtin_cheerp_get_thread_pointer();
	return ret == 0? &__dummy_thread : ret;
#else
	return &__dummy_thread;
#endif
}

#define MC_PC gregs[REG_EIP]

#endif // __CHEERP_PTHREAD_ARCH_H
