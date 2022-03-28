#ifndef __CHEERP_PTHREAD_ARCH_H
#define __CHEERP_PTHREAD_ARCH_H
struct __pthread; 
extern struct __pthread __dummy_thread;
static inline struct __pthread* __get_tp()
{
	return &__dummy_thread;
}

#define MC_PC gregs[REG_EIP]

#endif // __CHEERP_PTHREAD_ARCH_H
