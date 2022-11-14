#include "libc.h"
#include "pthread_arch.h"
#include "pthread_impl.h"

// __fini_array* are relevant only for dynamic linking, and are only defined in ldso/dynlink.c
// native builds will work regardless, but at link-time Cheerp will potentially crash
// (if libc_exit_fini still happens to be alive)
hidden void (*const __fini_dummy_initializer)(void) = 0;
weak_alias(__fini_dummy_initializer, __fini_array_end);
weak_alias(__fini_dummy_initializer, __fini_array_start);

__attribute__((constructor(0)))
void __cheerp_init_tp()
{
	pthread_t td = __get_tp();
	td->self = td;
	libc.can_do_threads = 1;
	td->detach_state = DT_JOINABLE;
	td->tid = 1;
	td->locale = &libc.global_locale;
	td->robust_list.head = &td->robust_list.head;
	td->sysinfo = __sysinfo;
	td->next = td->prev = td;
}
