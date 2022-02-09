#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))

__attribute((cheerp_genericjs))
static inline long __syscall0(long n)
{
	unsigned long __ret = 0;
	__asm__("console.log('syscall0', %0)" : : "r"(n));
	return __ret;
}

__attribute((cheerp_genericjs))
static inline long __syscall1(long n, long a1)
{
	unsigned long __ret = 0;
	__asm__("console.log('syscall1', %0, %1)" : : "r"(n), "r"(a1));
	return __ret;
}

__attribute((cheerp_genericjs))
static inline long __syscall2(long n, long a1, long a2)
{
	unsigned long __ret = 0;
	__asm__("console.log('syscall2', %0, %1, %2)" : : "r"(n), "r"(a1), "r"(a2));
	return __ret;
}

__attribute((cheerp_genericjs))
static inline long __syscall3(long n, long a1, long a2, long a3)
{
	unsigned long __ret = -1;
	__asm__("console.log('syscall3', %0, %1, %2, %3)" : : "r"(n), "r"(a1), "r"(a2), "r"(a3));
	return __ret;
}

__attribute((cheerp_genericjs))
static inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
	unsigned long __ret = 0;
	__asm__("console.log('syscall4', %0, %1, %2, %3, %4)" : : "r"(n), "r"(a1), "r"(a2), "r"(a3), "r"(a4));
	return __ret;
}

__attribute((cheerp_genericjs))
static inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	unsigned long __ret = 0;
	__asm__("console.log('syscall5', %0, %1, %2, %3, %4, %5)" : : "r"(n), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5));
	return __ret;
}

__attribute((cheerp_genericjs))
static inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	unsigned long __ret = 0;
	__asm__("console.log('syscall6', %0, %1, %2, %3, %4, %5, %6)" : : "r"(n), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6));
	return __ret;
}

#define VDSO_USEFUL
#define VDSO_CGT32_SYM "__vdso_clock_gettime"
#define VDSO_CGT32_VER "LINUX_2.6"
#define VDSO_CGT_SYM "__vdso_clock_gettime64"
#define VDSO_CGT_VER "LINUX_2.6"
