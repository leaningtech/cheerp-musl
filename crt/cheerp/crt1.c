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
void* volatile __tlsImage = 0x0;
void* volatile __tlsImageSize = 0x0;

void __cheerp_init_tls()
{
	main_tls.image = __tlsImage;
	main_tls.size = __tlsImageSize;
	main_tls.len = __tlsImageSize;
	main_tls.align = 16; // ???
	main_tls.offset = main_tls.size;
	libc.tls_cnt = 1;
	libc.tls_head = &main_tls;
	libc.tls_align = main_tls.align;
	libc.tls_size = 2*sizeof(void *) + sizeof(struct pthread) + main_tls.size + main_tls.align;
	unsigned char *mem = (unsigned char*)malloc(libc.tls_size);
	memset(mem, 0, libc.tls_size);
	__init_tp(__copy_tls(mem));
}
