COMPAT_SRC_DIRS = compat/time32
SYSCALL_LIST = $(srcdir)/arch/cheerp/bits/syscall_list.h
# Inside the libc, SYS_* name the syscall entry functions, which are called directly
CFLAGS_ALL += -D_CHEERP_DIRECT_SYSCALLS
