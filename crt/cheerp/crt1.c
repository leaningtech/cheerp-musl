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

void *__cheerp_malloc(size_t n);

void __cheerp_init_tls()
{
	// Be robust to spurious TLS initialization from shared modules
	// TODO: This code should not be called at all for libraries
	if(main_tls.image != 0)
		return;
	main_tls.image = __tlsImage;
	main_tls.size = __tlsImageSize;
	main_tls.len = __tlsImageSize;
	main_tls.align = 16; // ???
	main_tls.offset = main_tls.size;
	libc.tls_cnt = 1;
	libc.tls_head = &main_tls;
	libc.tls_align = main_tls.align;
	libc.tls_size = 2*sizeof(void *) + sizeof(struct pthread) + main_tls.size + main_tls.align;
	unsigned char *mem = (unsigned char*)__cheerp_malloc(libc.tls_size);
	memset(mem, 0, libc.tls_size);
	struct pthread* self = __copy_tls(mem);
	self->map_base = mem;
	__init_tp(self);
}
