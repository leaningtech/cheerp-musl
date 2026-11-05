#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))

#define __SYSCALL_DIRECT 1


//#define VDSO_USEFUL
//#define VDSO_CGT32_SYM "__vdso_clock_gettime"
//#define VDSO_CGT32_VER "LINUX_2.6"
//#define VDSO_CGT_SYM "__vdso_clock_gettime64"
//#define VDSO_CGT_VER "LINUX_2.6"
