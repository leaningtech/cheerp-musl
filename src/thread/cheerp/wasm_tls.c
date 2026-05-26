#include <stdint.h>

#if defined(__wasm__) && !defined(__CHEERP__)
__asm__(".globaltype __tls_base, i32");
__asm__(".globaltype __tls_size, i32, immutable");
__asm__(".globaltype __tls_align, i32, immutable");

__attribute__((__naked__, __visibility__("hidden")))
uintptr_t __clang_wasm_tls_base(void)
{
	__asm__("global.get __tls_base");
}

__attribute__((__naked__, __visibility__("hidden")))
void __clang_wasm_set_tls_base(uintptr_t p)
{
	__asm__("local.get 0\nglobal.set __tls_base");
}

__attribute__((__naked__, __visibility__("hidden")))
uintptr_t __clang_wasm_tls_size(void)
{
	__asm__("global.get __tls_size");
}

__attribute__((__naked__, __visibility__("hidden")))
uintptr_t __clang_wasm_tls_align(void)
{
	__asm__("global.get __tls_align");
}
#endif
