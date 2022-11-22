#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))

long __syscall_restart_syscall(long a1,...);
long __syscall_exit();
long __syscall_fork();
long __syscall_read(long a1,...);
long __syscall_write(long a1,...);
long __syscall_open(const char* pathname, int flags, ...);
long __syscall_close(long a1,...);
long __syscall_waitpid(long a1,...);
long __syscall_creat(long a1,...);
long __syscall_link(long a1,...);
long __syscall_unlink(long a1,...);
long __syscall_execve(long a1,...);
long __syscall_chdir(long a1,...);
long __syscall_time(long a1,...);
long __syscall_mknod(long a1,...);
long __syscall_chmod(long a1,...);
long __syscall_lchown(long a1,...);
long __syscall_break(long a1,...);
long __syscall_oldstat(long a1,...);
long __syscall_lseek(long a1,...);
long __syscall_getpid();
long __syscall_mount(long a1,...);
long __syscall_umount(long a1,...);
long __syscall_setuid(long a1,...);
long __syscall_getuid();
long __syscall_stime(long a1,...);
long __syscall_ptrace(long a1,...);
long __syscall_alarm(long a1,...);
long __syscall_oldfstat(long a1,...);
long __syscall_pause();
long __syscall_utime(long a1,...);
long __syscall_stty(long a1,...);
long __syscall_gtty(long a1,...);
long __syscall_access(long a1,...);
long __syscall_nice(long a1,...);
long __syscall_ftime(long a1,...);
long __syscall_sync();
long __syscall_kill(long a1,...);
long __syscall_rename(long a1,...);
long __syscall_mkdir(long a1,...);
long __syscall_rmdir(long a1,...);
long __syscall_dup(long a1,...);
long __syscall_pipe(long a1,...);
long __syscall_times(long a1,...);
long __syscall_prof(long a1,...);
long __syscall_brk(void* newaddr);
long __syscall_setgid(long a1,...);
long __syscall_getgid(long a1,...);
long __syscall_signal(long a1,...);
long __syscall_geteuid(long a1,...);
long __syscall_getegid(long a1,...);
long __syscall_acct(long a1,...);
long __syscall_umount2(long a1,...);
long __syscall_lock(long a1,...);
long __syscall_ioctl(long fd, long req, void* arg);
long __syscall_fcntl(long a1,...);
long __syscall_mpx(long a1,...);
long __syscall_setpgid(long a1,...);
long __syscall_ulimit(long a1,...);
long __syscall_oldolduname(long a1,...);
long __syscall_umask(long a1,...);
long __syscall_chroot(long a1,...);
long __syscall_ustat(long a1,...);
long __syscall_dup2(long a1,...);
long __syscall_getppid();
long __syscall_getpgrp();
long __syscall_setsid();
long __syscall_sigaction(long a1,...);
long __syscall_sgetmask(long a1,...);
long __syscall_ssetmask(long a1,...);
long __syscall_setreuid(long a1,...);
long __syscall_setregid(long a1,...);
long __syscall_sigsuspend(long a1,...);
long __syscall_sigpending(long a1,...);
long __syscall_sethostname(long a1,...);
long __syscall_setrlimit(long a1,...);
long __syscall_getrlimit(long a1,...);
long __syscall_getrusage(long a1,...);
long __syscall_gettimeofday_time32(long a1,...);
long __syscall_settimeofday_time32(long a1,...);
long __syscall_getgroups(long a1,...);
long __syscall_setgroups(long a1,...);
long __syscall_select(long a1,...);
long __syscall_symlink(long a1,...);
long __syscall_oldlstat(long a1,...);
long __syscall_readlink(long a1,...);
long __syscall_uselib(long a1,...);
long __syscall_swapon(long a1,...);
long __syscall_reboot(long a1,...);
long __syscall_readdir(long a1,...);
long __syscall_mmap(long a1,...);
long __syscall_munmap(long a1, long length);
long __syscall_truncate(long a1,...);
long __syscall_ftruncate(long a1,...);
long __syscall_fchmod(long a1,...);
long __syscall_fchown(long a1,...);
long __syscall_getpriority(long a1,...);
long __syscall_setpriority(long a1,...);
long __syscall_profil(long a1,...);
long __syscall_statfs(long a1,...);
long __syscall_fstatfs(long a1,...);
long __syscall_ioperm(long a1,...);
long __syscall_socketcall(long a1,...);
long __syscall_syslog(long a1,...);
long __syscall_setitimer(long a1,...);
long __syscall_getitimer(long a1,...);
long __syscall_stat(long a1,...);
long __syscall_lstat(long a1,...);
long __syscall_fstat(long a1,...);
long __syscall_olduname(long a1,...);
long __syscall_iopl(long a1,...);
long __syscall_vhangup();
long __syscall_idle(long a1,...);
long __syscall_vm86old(long a1,...);
long __syscall_wait4(long a1,...);
long __syscall_swapoff(long a1,...);
long __syscall_sysinfo(long a1,...);
long __syscall_ipc(long a1,...);
long __syscall_fsync(long a1,...);
long __syscall_sigreturn(long a1,...);
long __syscall_clone(long a1,...);
long __syscall_setdomainname(long a1,...);
long __syscall_uname(long a1,...);
long __syscall_modify_ldt(long a1,...);
long __syscall_adjtimex(long a1,...);
long __syscall_mprotect(long a1,...);
long __syscall_sigprocmask(long a1,...);
long __syscall_create_module(long a1,...);
long __syscall_init_module(long a1,...);
long __syscall_delete_module(long a1,...);
long __syscall_get_kernel_syms(long a1,...);
long __syscall_quotactl(long a1,...);
long __syscall_getpgid(long a1,...);
long __syscall_fchdir(long a1,...);
long __syscall_bdflush(long a1,...);
long __syscall_sysfs(long a1,...);
long __syscall_personality(long a1,...);
long __syscall_afs_syscall(long a1,...);
long __syscall_setfsuid(long a1,...);
long __syscall_setfsgid(long a1,...);
long __syscall__llseek(unsigned int a1, unsigned long a2, unsigned long a3, long* a4, unsigned int a5);
long __syscall_getdents(long a1,...);
long __syscall__newselect(long a1,...);
long __syscall_flock(long a1,...);
long __syscall_msync(long a1,...);
long __syscall_readv(long a1,...);
struct iovec;
long __syscall_writev(long fd, const struct iovec* ios, long len);
long __syscall_getsid(long a1,...);
long __syscall_fdatasync(long a1,...);
long __syscall__sysctl(long a1,...);
long __syscall_mlock(long a1,...);
long __syscall_munlock(long a1,...);
long __syscall_mlockall(long a1,...);
long __syscall_munlockall();
long __syscall_sched_setparam(long a1,...);
long __syscall_sched_getparam(long a1,...);
long __syscall_sched_setscheduler(long a1,...);
long __syscall_sched_getscheduler(long a1,...);
long __syscall_sched_yield();
long __syscall_sched_get_priority_max(long a1,...);
long __syscall_sched_get_priority_min(long a1,...);
long __syscall_sched_rr_get_interval(long a1,...);
long __syscall_nanosleep(long a1,...);
long __syscall_mremap(long old_addr, long old_len, long new_len, long flags, long new_addr);
long __syscall_setresuid(long a1,...);
long __syscall_getresuid(long a1,...);
long __syscall_vm86(long a1,...);
long __syscall_query_module(long a1,...);
long __syscall_poll(long a1,...);
long __syscall_nfsservctl(long a1,...);
long __syscall_setresgid(long a1,...);
long __syscall_getresgid(long a1,...);
long __syscall_prctl(long a1,...);
long __syscall_rt_sigreturn(long a1,...);
long __syscall_rt_sigaction(long a1,...);
long __syscall_rt_sigprocmask(long a1,...);
long __syscall_rt_sigpending(long a1,...);
long __syscall_rt_sigtimedwait(long a1,...);
long __syscall_rt_sigqueueinfo(long a1,...);
long __syscall_rt_sigsuspend(long a1,...);
long __syscall_pread64(long a1,...);
long __syscall_pwrite64(long a1,...);
long __syscall_chown(long a1,...);
char* __syscall_getcwd(char* a1, long a2);
long __syscall_capget(long a1,...);
long __syscall_capset(long a1,...);
long __syscall_sigaltstack(long a1,...);
long __syscall_sendfile(long a1,...);
long __syscall_getpmsg(long a1,...);
long __syscall_putpmsg(long a1,...);
long __syscall_vfork(long a1,...);
long __syscall_ugetrlimit(long a1,...);
long __syscall_mmap2(long a1, long a2, long a3, long a4, long a5, long a6);
long __syscall_truncate64(long a1,...);
long __syscall_ftruncate64(long a1,...);
long __syscall_stat64(long a1,...);
long __syscall_lstat64(long a1,...);
long __syscall_fstat64(long a1,...);
long __syscall_lchown32(long a1,...);
long __syscall_getuid32();
long __syscall_getgid32();
long __syscall_geteuid32();
long __syscall_getegid32();
long __syscall_setreuid32(long a1,...);
long __syscall_setregid32(long a1,...);
long __syscall_getgroups32(long a1,...);
long __syscall_setgroups32(long a1,...);
long __syscall_fchown32(long a1,...);
long __syscall_setresuid32(long a1,...);
long __syscall_getresuid32(long a1,...);
long __syscall_setresgid32(long a1,...);
long __syscall_getresgid32(long a1,...);
long __syscall_chown32(long a1,...);
long __syscall_setuid32(long a1,...);
long __syscall_setgid32(long a1,...);
long __syscall_setfsuid32(long a1,...);
long __syscall_setfsgid32(long a1,...);
long __syscall_pivot_root(long a1,...);
long __syscall_mincore(long a1,...);
long __syscall_madvise(void* addr, long length, long advice);
long __syscall_getdents64(long a1,...);
long __syscall_fcntl64(long a1,...);
long __syscall_gettid();
long __syscall_readahead(long a1,...);
long __syscall_setxattr(long a1,...);
long __syscall_lsetxattr(long a1,...);
long __syscall_fsetxattr(long a1,...);
long __syscall_getxattr(long a1,...);
long __syscall_lgetxattr(long a1,...);
long __syscall_fgetxattr(long a1,...);
long __syscall_listxattr(long a1,...);
long __syscall_llistxattr(long a1,...);
long __syscall_flistxattr(long a1,...);
long __syscall_removexattr(long a1,...);
long __syscall_lremovexattr(long a1,...);
long __syscall_fremovexattr(long a1,...);
long __syscall_tkill(long a1,...);
long __syscall_sendfile64(long a1,...);
long __syscall_futex(int* a1,...);
long __syscall_sched_setaffinity(long a1,...);
long __syscall_sched_getaffinity(long a1,...);
long __syscall_set_thread_area(long a1,...);
long __syscall_get_thread_area(long a1,...);
long __syscall_io_setup(long a1,...);
long __syscall_io_destroy(long a1,...);
long __syscall_io_getevents(long a1,...);
long __syscall_io_submit(long a1,...);
long __syscall_io_cancel(long a1,...);
long __syscall_fadvise64(long a1,...);
long __syscall_exit_group(long a1,...);
long __syscall_lookup_dcookie(long a1,...);
long __syscall_epoll_create(long a1,...);
long __syscall_epoll_ctl(long a1,...);
long __syscall_epoll_wait(long a1,...);
long __syscall_remap_file_pages(long a1,...);
long __syscall_set_tid_address(long a1,...);
long __syscall_timer_create(long a1,...);
long __syscall_timer_settime32(long a1,...);
long __syscall_timer_gettime32(long a1,...);
long __syscall_timer_getoverrun(long a1,...);
long __syscall_timer_delete(long a1,...);
long __syscall_clock_settime32(long a1,...);
long __syscall_clock_gettime32(long a1,...);
long __syscall_clock_getres_time32(long a1,...);
long __syscall_clock_nanosleep_time32(long a1,...);
long __syscall_statfs64(long a1,...);
long __syscall_fstatfs64(long a1,...);
long __syscall_tgkill(long a1,...);
long __syscall_utimes(long a1,...);
long __syscall_fadvise64_64(long a1,...);
long __syscall_vserver(long a1,...);
long __syscall_mbind(long a1,...);
long __syscall_get_mempolicy(long a1,...);
long __syscall_set_mempolicy(long a1,...);
long __syscall_mq_open(long a1,...);
long __syscall_mq_unlink(long a1,...);
long __syscall_mq_timedsend(long a1,...);
long __syscall_mq_timedreceive(long a1,...);
long __syscall_mq_notify(long a1,...);
long __syscall_mq_getsetattr(long a1,...);
long __syscall_kexec_load(long a1,...);
long __syscall_waitid(long a1,...);
long __syscall_sys_setaltroot(long a1,...);
long __syscall_add_key(long a1,...);
long __syscall_request_key(long a1,...);
long __syscall_keyctl(long a1,...);
long __syscall_ioprio_set(long a1,...);
long __syscall_ioprio_get(long a1,...);
long __syscall_inotify_init();
long __syscall_inotify_add_watch(long a1,...);
long __syscall_inotify_rm_watch(long a1,...);
long __syscall_migrate_pages(long a1,...);
long __syscall_openat(long a1,...);
long __syscall_mkdirat(long a1,...);
long __syscall_mknodat(long a1,...);
long __syscall_fchownat(long a1,...);
long __syscall_futimesat(long a1,...);
long __syscall_fstatat64(long a1,...);
long __syscall_unlinkat(long a1,...);
long __syscall_renameat(long a1,...);
long __syscall_linkat(long a1,...);
long __syscall_symlinkat(long a1,...);
long __syscall_readlinkat(long a1,...);
long __syscall_fchmodat(long a1,...);
long __syscall_faccessat(long a1,...);
long __syscall_pselect6(long a1,...);
long __syscall_ppoll(long a1,...);
long __syscall_unshare(long a1,...);
long __syscall_set_robust_list(long a1,...);
long __syscall_get_robust_list(long a1,...);
long __syscall_splice(long a1,...);
long __syscall_sync_file_range(long a1,...);
long __syscall_tee(long a1,...);
long __syscall_vmsplice(long a1,...);
long __syscall_move_pages(long a1,...);
long __syscall_getcpu(long a1,...);
long __syscall_epoll_pwait(long a1,...);
long __syscall_utimensat(long a1,...);
long __syscall_signalfd(long a1,...);
long __syscall_timerfd_create(long a1,...);
long __syscall_eventfd(long a1,...);
long __syscall_fallocate(long a1,...);
long __syscall_timerfd_settime32(long a1,...);
long __syscall_timerfd_gettime32(long a1,...);
long __syscall_signalfd4(long a1,...);
long __syscall_eventfd2(long a1,...);
long __syscall_epoll_create1(long a1,...);
long __syscall_dup3(long a1,...);
long __syscall_pipe2(long a1,...);
long __syscall_inotify_init1(long a1,...);
long __syscall_preadv(long a1,...);
long __syscall_pwritev(long a1,...);
long __syscall_rt_tgsigqueueinfo(long a1,...);
long __syscall_perf_event_open(long a1,...);
long __syscall_recvmmsg(long a1,...);
long __syscall_fanotify_init(long a1,...);
long __syscall_fanotify_mark(long a1,...);
long __syscall_prlimit64(long a1,...);
long __syscall_name_to_handle_at(long a1,...);
long __syscall_open_by_handle_at(long a1,...);
long __syscall_clock_adjtime(long a1,...);
long __syscall_syncfs(long a1,...);
long __syscall_sendmmsg(long a1,...);
long __syscall_setns(long a1,...);
long __syscall_process_vm_readv(long a1,...);
long __syscall_process_vm_writev(long a1,...);
long __syscall_kcmp(long a1,...);
long __syscall_finit_module(long a1,...);
long __syscall_sched_setattr(long a1,...);
long __syscall_sched_getattr(long a1,...);
long __syscall_renameat2(long a1,...);
long __syscall_seccomp(long a1,...);
long __syscall_getrandom(long a1,...);
long __syscall_memfd_create(long a1,...);
long __syscall_bpf(long a1,...);
long __syscall_execveat(long a1,...);
long __syscall_socket(long a1,...);
long __syscall_socketpair(long a1,...);
long __syscall_bind(long a1,...);
long __syscall_connect(long a1,...);
long __syscall_listen(long a1,...);
long __syscall_accept4(long a1,...);
long __syscall_getsockopt(long a1,...);
long __syscall_setsockopt(long a1,...);
long __syscall_getsockname(long a1,...);
long __syscall_getpeername(long a1,...);
long __syscall_sendto(long a1,...);
long __syscall_sendmsg(long a1,...);
long __syscall_recvfrom(long a1,...);
long __syscall_recvmsg(long a1,...);
long __syscall_shutdown(long a1,...);
long __syscall_userfaultfd(long a1,...);
long __syscall_membarrier(long a1,...);
long __syscall_mlock2(long a1,...);
long __syscall_copy_file_range(long a1,...);
long __syscall_preadv2(long a1,...);
long __syscall_pwritev2(long a1,...);
long __syscall_pkey_mprotect(long a1,...);
long __syscall_pkey_alloc(long a1,...);
long __syscall_pkey_free(long a1,...);
long __syscall_statx(long a1,...);
long __syscall_arch_prctl(long a1,...);
long __syscall_io_pgetevents(long a1,...);
long __syscall_rseq(long a1,...);
long __syscall_semget(long a1,...);
long __syscall_semctl(long a1,...);
long __syscall_shmget(long a1,...);
long __syscall_shmctl(long a1,...);
long __syscall_shmat(long a1,...);
long __syscall_shmdt(long a1,...);
long __syscall_msgget(long a1,...);
long __syscall_msgsnd(long a1,...);
long __syscall_msgrcv(long a1,...);
long __syscall_msgctl(long a1,...);
struct timespec;
long __syscall_clock_gettime64(int clk_id, struct timespec* res);
long __syscall_clock_settime64(long a1,...);
long __syscall_clock_adjtime64(long a1,...);
long __syscall_clock_getres_time64(long a1,...);
long __syscall_clock_nanosleep_time64(long a1,...);
long __syscall_timer_gettime64(long a1,...);
long __syscall_timer_settime64(long a1,...);
long __syscall_timerfd_gettime64(long a1,...);
long __syscall_timerfd_settime64(long a1,...);
long __syscall_utimensat_time64(long a1,...);
long __syscall_pselect6_time64(long a1,...);
long __syscall_ppoll_time64(long a1,...);
long __syscall_io_pgetevents_time64(long a1,...);
long __syscall_recvmmsg_time64(long a1,...);
long __syscall_mq_timedsend_time64(long a1,...);
long __syscall_mq_timedreceive_time64(long a1,...);
long __syscall_semtimedop_time64(long a1,...);
long __syscall_rt_sigtimedwait_time64(long a1,...);
long __syscall_futex_time64(long a1,...);
long __syscall_sched_rr_get_interval_time64(long a1,...);
long __syscall_pidfd_send_signal(long a1,...);
long __syscall_io_uring_setup(long a1,...);
long __syscall_io_uring_enter(long a1,...);
long __syscall_io_uring_register(long a1,...);
long __syscall_open_tree(long a1,...);
long __syscall_move_mount(long a1,...);
long __syscall_fsopen(long a1,...);
long __syscall_fsconfig(long a1,...);
long __syscall_fsmount(long a1,...);
long __syscall_fspick(long a1,...);
long __syscall_pidfd_open(long a1,...);
long __syscall_clone3(long a1,...);
long __syscall_close_range(long a1,...);
long __syscall_openat2(long a1,...);
long __syscall_pidfd_getfd(long a1,...);
long __syscall_faccessat2(long a1,...);
long __syscall_process_madvise(long a1,...);


//#define VDSO_USEFUL
//#define VDSO_CGT32_SYM "__vdso_clock_gettime"
//#define VDSO_CGT32_VER "LINUX_2.6"
//#define VDSO_CGT_SYM "__vdso_clock_gettime64"
//#define VDSO_CGT_VER "LINUX_2.6"
