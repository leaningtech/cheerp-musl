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
	syscall_arg_t a,b,c,d,e,f;
#ifdef __SYSCALL_DIRECT
	syscall_arg_t g;
#endif
	va_start(ap, n);
	a=va_arg(ap, syscall_arg_t);
	b=va_arg(ap, syscall_arg_t);
	c=va_arg(ap, syscall_arg_t);
	d=va_arg(ap, syscall_arg_t);
	e=va_arg(ap, syscall_arg_t);
	f=va_arg(ap, syscall_arg_t);
#ifdef __SYSCALL_DIRECT
	g=va_arg(ap, syscall_arg_t);
#endif
	va_end(ap);
#ifndef __SYSCALL_DIRECT
	return __syscall_ret(__syscall(n,a,b,c,d,e,f));
#else
	return __syscall_ret(__syscall_dispatch(n,a,b,c,d,e,f,g));
#endif
#endif
}
