#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))

__attribute((cheerp_genericjs))
long __syscall0(long n);

__attribute((cheerp_genericjs))
long __syscall1(long n, long a1);

__attribute((cheerp_genericjs))
long __syscall2(long n, long a1, long a2);

__attribute((cheerp_genericjs))
long __syscall3(long n, long a1, long a2, long a3);

__attribute((cheerp_genericjs))
long __syscall4(long n, long a1, long a2, long a3, long a4);

__attribute((cheerp_genericjs))
long __syscall5(long n, long a1, long a2, long a3, long a4, long a5);

__attribute((cheerp_genericjs))
long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6);

#define VDSO_USEFUL
#define VDSO_CGT32_SYM "__vdso_clock_gettime"
#define VDSO_CGT32_VER "LINUX_2.6"
#define VDSO_CGT_SYM "__vdso_clock_gettime64"
#define VDSO_CGT_VER "LINUX_2.6"
