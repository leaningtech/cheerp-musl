#define _BSD_SOURCE
#include <unistd.h>
#include "syscall.h"
#include <stdarg.h>

#undef syscall

#if defined(__SYSCALL_DIRECT) && !(defined(__CHEERP__) && !defined(__ASMJS__))
#define __CHEERP_SYSCALL_DISPATCH 1
#define __CHEERP_SYSCALL_NARGS_X(_0,_1,_2,_3,_4,_5,_6,N,...) N
#define __CHEERP_SYSCALL_NARGS(...) __CHEERP_SYSCALL_NARGS_X(_, __VA_ARGS__ __VA_OPT__(,) 6, 5, 4, 3, 2, 1, 0)

#define __CHEERP_SYSCALL_CAT_X(a,b) a ## b
#define __CHEERP_SYSCALL_CAT(a,b) __CHEERP_SYSCALL_CAT_X(a,b)
#define __CHEERP_SYSCALL_SECOND(a,b,...) b
#define __CHEERP_SYSCALL_PROBE() ~, 1
#define __CHEERP_SYSCALL_IS_PROBE(...) __CHEERP_SYSCALL_SECOND(__VA_ARGS__, 0)

#define __CHEERP_SYSCALL_CASE_PROBE_open __CHEERP_SYSCALL_PROBE()
#define __CHEERP_SYSCALL_CASE_PROBE_ipc __CHEERP_SYSCALL_PROBE()
#define __CHEERP_SYSCALL_CASE_PROBE_fcntl64 __CHEERP_SYSCALL_PROBE()
#define __CHEERP_SYSCALL_CASE_PROBE_futex __CHEERP_SYSCALL_PROBE()
#define __CHEERP_SYSCALL_CASE_PROBE_openat __CHEERP_SYSCALL_PROBE()
#define __CHEERP_SYSCALL_CASE_PROBE_clone4 __CHEERP_SYSCALL_PROBE()
#define __CHEERP_SYSCALL_HAS_CASE(name) __CHEERP_SYSCALL_IS_PROBE(__CHEERP_SYSCALL_CAT(__CHEERP_SYSCALL_CASE_PROBE_, name))

#define SYSCALL_DEF(name, ...) __CHEERP_SYSCALL_CAT(__CHEERP_SYSCALL_SELECT_, __CHEERP_SYSCALL_HAS_CASE(name))(name, __VA_ARGS__)
#define __CHEERP_SYSCALL_SELECT_0(name, ...) __CHEERP_SYSCALL_CAT(__CHEERP_SYSCALL_DISPATCH_, __CHEERP_SYSCALL_NARGS(__VA_ARGS__))(name);
#define __CHEERP_SYSCALL_SELECT_1(name, ...) __CHEERP_SYSCALL_CAT(__CHEERP_SYSCALL_CASE_, name)();

#define __CHEERP_SYSCALL_CASE_open() \
	case __NR_open: return __syscall_ret(__syscall_open((const char *)a, (int)b, c))
#define __CHEERP_SYSCALL_CASE_ipc() \
	case __NR_ipc: return __syscall_ret(__syscall_ipc(a, b, c, d, e, f))
#define __CHEERP_SYSCALL_CASE_fcntl64() \
	case __NR_fcntl64: return __syscall_ret(__syscall_fcntl64((int)a, (int)b, c))
#define __CHEERP_SYSCALL_CASE_futex() \
	case __NR_futex: return __syscall_ret(__syscall_futex((int *)a, (int)b, c, d, e, f))
#define __CHEERP_SYSCALL_CASE_openat() \
	case __NR_openat: return __syscall_ret(__syscall_openat((int)a, (const char *)b, (int)c, d))
#define __CHEERP_SYSCALL_CASE_clone4() \
	case __NR_clone4: return __syscall_ret(__syscall_clone4((int (*)(void *))a, (void *)b, (int)c, (void *)d, (void *)e, (void *)f, (void *)g))

#define __CHEERP_SYSCALL_DISPATCH_0(name) \
	case __NR_ ## name: return __syscall_ret(((long (*)(void))__syscall_ ## name)())
#define __CHEERP_SYSCALL_DISPATCH_1(name) \
	case __NR_ ## name: return __syscall_ret(((long (*)(syscall_arg_t))__syscall_ ## name)(a))
#define __CHEERP_SYSCALL_DISPATCH_2(name) \
	case __NR_ ## name: return __syscall_ret(((long (*)(syscall_arg_t, syscall_arg_t))__syscall_ ## name)(a, b))
#define __CHEERP_SYSCALL_DISPATCH_3(name) \
	case __NR_ ## name: return __syscall_ret(((long (*)(syscall_arg_t, syscall_arg_t, syscall_arg_t))__syscall_ ## name)(a, b, c))
#define __CHEERP_SYSCALL_DISPATCH_4(name) \
	case __NR_ ## name: return __syscall_ret(((long (*)(syscall_arg_t, syscall_arg_t, syscall_arg_t, syscall_arg_t))__syscall_ ## name)(a, b, c, d))
#define __CHEERP_SYSCALL_DISPATCH_5(name) \
	case __NR_ ## name: return __syscall_ret(((long (*)(syscall_arg_t, syscall_arg_t, syscall_arg_t, syscall_arg_t, syscall_arg_t))__syscall_ ## name)(a, b, c, d, e))
#define __CHEERP_SYSCALL_DISPATCH_6(name) \
	case __NR_ ## name: return __syscall_ret(((long (*)(syscall_arg_t, syscall_arg_t, syscall_arg_t, syscall_arg_t, syscall_arg_t, syscall_arg_t))__syscall_ ## name)(a, b, c, d, e, f))
#endif

long syscall(long n, ...)
{
#if defined(__CHEERP__) && !defined(__ASMJS__)
	return -1;
#else
	va_list ap;
	syscall_arg_t a,b,c,d,e,f;
#ifdef __CHEERP_SYSCALL_DISPATCH
	syscall_arg_t g;
#endif
	va_start(ap, n);
	a=va_arg(ap, syscall_arg_t);
	b=va_arg(ap, syscall_arg_t);
	c=va_arg(ap, syscall_arg_t);
	d=va_arg(ap, syscall_arg_t);
	e=va_arg(ap, syscall_arg_t);
	f=va_arg(ap, syscall_arg_t);
#ifdef __CHEERP_SYSCALL_DISPATCH
	g=va_arg(ap, syscall_arg_t);
#endif
	va_end(ap);
#ifndef __CHEERP_SYSCALL_DISPATCH
	return __syscall_ret(__syscall(n,a,b,c,d,e,f));
#else
	switch (n) {
#include "syscall_arch.h"
	default:
		return __syscall_ret(-ENOSYS);
	}
#endif
#endif
}
