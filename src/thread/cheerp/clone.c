#include "syscall.h"
#include <stdarg.h>
#include <sys/types.h>

int __clone(int (*func)(void *), void *stack, int flags, void *arg, ...)
{
	va_list ap;
	pid_t *ptid, *ctid;
	void  *tls;

	va_start(ap, arg);
	ptid = va_arg(ap, pid_t *);
	tls  = va_arg(ap, void *);
	ctid = va_arg(ap, pid_t *);
	va_end(ap);

	return __syscall(SYS_clone4, func, stack, flags, arg, ptid, tls, ctid);
}
