#include "libc.h"
#include "pthread_arch.h"
#include "pthread_impl.h"

weak int main(int argc, char* argv[])
{
}
weak void webMain()
{
	main(0, NULL);
}
void __cheerp_constructors(void);

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

__attribute((cheerp_genericjs))
void _start()
{
	__cheerp_constructors();
	webMain();
}
