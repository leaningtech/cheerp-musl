#include "libc.h"
#include "pthread_arch.h"
#include "pthread_impl.h"
#include "string.h"

// __fini_array* are relevant only for dynamic linking, and are only defined in ldso/dynlink.c
// native builds will work regardless, but at link-time Cheerp will potentially crash
// (if libc_exit_fini still happens to be alive)
hidden void (*const __fini_dummy_initializer)(void) = 0;
weak_alias(__fini_dummy_initializer, __fini_array_end);
weak_alias(__fini_dummy_initializer, __fini_array_start);

static struct tls_module main_tls;
// These values will be populated by LinearMemoryHelper
unsigned int volatile __tlsImage = 0x0;
size_t volatile __tlsImageSize = 0;

#if defined(__wasm__) && !defined(__CHEERP__)
extern void __wasm_init_tls(void *);
#endif

void *__cheerp_malloc(size_t n);

void __cheerp_init_tls()
{
	// Be robust to spurious TLS initialization from shared modules
	// TODO: This code should not be called at all for libraries
	if(main_tls.image != 0)
		return;
#if defined(__wasm__) && !defined(__CHEERP__)
	size_t tls_size = __clang_wasm_tls_size_aligned();
	size_t tls_align = __clang_wasm_tls_align();
	if (tls_align < 16)
		tls_align = 16;
	// upstream wasm clang installs the TLS data image via __wasm_init_tls, so
	// there is no image to copy here. Use a non-null marker so re-entry is
	// detected like in the Cheerp path; main_tls.len stays 0 so it is never read.
	main_tls.image = &main_tls;
	main_tls.size = tls_size;
	main_tls.len = 0;
	main_tls.align = tls_align;
	main_tls.offset = tls_size;
#else
	main_tls.image = __tlsImage;
	main_tls.size = __tlsImageSize;
	main_tls.len = __tlsImageSize;
	main_tls.align = 16; // ???
	main_tls.offset = main_tls.size;
#endif
	libc.tls_cnt = 1;
	libc.tls_head = &main_tls;
	libc.tls_align = main_tls.align;
	libc.tls_size = 2*sizeof(void *) + sizeof(struct pthread) + main_tls.size + main_tls.align;
#if defined(__CHEERP__) && !defined(__ASMJS__)
	__init_tp(__get_tp());
#else
	unsigned char *mem = (unsigned char*)__cheerp_malloc(libc.tls_size);
	memset(mem, 0, libc.tls_size);
	struct pthread* self = __copy_tls(mem);
	self->map_base = mem;
#if defined(__wasm__) && !defined(__CHEERP__)
	void *tls_base = (unsigned char*)self - main_tls.offset;
	__wasm_init_tls(tls_base);
	__clang_wasm_set_tls_base((uintptr_t)tls_base);
#endif
	if (__init_tp(self) < 0)
		a_crash();
#endif
}
