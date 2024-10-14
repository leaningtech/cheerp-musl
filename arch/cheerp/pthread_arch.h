#ifndef __CHEERP_PTHREAD_ARCH_H
#define __CHEERP_PTHREAD_ARCH_H

struct __pthread; 
extern struct __pthread __dummy_thread;
static inline struct __pthread* __get_tp()
{
#ifdef __ASMJS__
	struct __pthread* ret = (struct __pthread*)__builtin_cheerp_get_thread_pointer();
	return ret == 0? &__dummy_thread : ret;
#else
	return &__dummy_thread;
#endif
}

#define MC_PC gregs[REG_EIP]

#endif // __CHEERP_PTHREAD_ARCH_H
