#define _BSD_SOURCE
#include <unistd.h>
#include "syscall.h"
#include <stdarg.h>

#undef syscall

long syscall(long n, ...)
{
#if defined(__CHEERP__) && !defined(__ASMJS__)
	return -1;
#else
	va_list ap;
	syscall_arg_t a,b,c,d,e,f,g;
	va_start(ap, n);
	a=va_arg(ap, syscall_arg_t);
	b=va_arg(ap, syscall_arg_t);
	c=va_arg(ap, syscall_arg_t);
	d=va_arg(ap, syscall_arg_t);
	e=va_arg(ap, syscall_arg_t);
	f=va_arg(ap, syscall_arg_t);
	g=va_arg(ap, syscall_arg_t);
	va_end(ap);
	return __syscall_ret(__syscall_dispatch(n,a,b,c,d,e,f,g));
#endif
}
