#ifndef __CHEERP_PTHREAD_ARCH_H
#define __CHEERP_PTHREAD_ARCH_H

unsigned int __builtin_cheerp_get_thread_pointer();

struct __pthread; 
extern struct __pthread __dummy_thread;
static inline struct __pthread* __get_tp()
{
#ifdef __ASMJS__
	return (struct __pthread*)__builtin_cheerp_get_thread_pointer();
#else
	return &__dummy_thread;
#endif
}

#define MC_PC gregs[REG_EIP]

#endif // __CHEERP_PTHREAD_ARCH_H
