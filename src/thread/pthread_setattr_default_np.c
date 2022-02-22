#define _GNU_SOURCE
#include "pthread_impl.h"
#include <string.h>

#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((a)>(b) ? (a) : (b))


#if defined(__CHEERP__) && !defined(__ASMJS__)
static int pthread_attr_memcmp(pthread_attr_t* a, pthread_attr_t* b, int s)
{
	if (a->__u.__i != b->__u.__i)
		return -1;
	if (a->__u.__vi != b->__u.__vi)
		return -1;
	if (a->__u.__s != b->__u.__s)
		return -1;
	return 0;
}
#else
#define pthread_attr_memcmp memcmp
#endif

int pthread_setattr_default_np(const pthread_attr_t *attrp)
{
	/* Reject anything in the attr object other than stack/guard size. */
	pthread_attr_t tmp = *attrp, zero = { 0 };
	tmp._a_stacksize = 0;
	tmp._a_guardsize = 0;
	if (pthread_attr_memcmp(&tmp, &zero, sizeof tmp))
		return EINVAL;

	unsigned stack = MIN(attrp->_a_stacksize, DEFAULT_STACK_MAX);
	unsigned guard = MIN(attrp->_a_guardsize, DEFAULT_GUARD_MAX);

	__inhibit_ptc();
	__default_stacksize = MAX(__default_stacksize, stack);
	__default_guardsize = MAX(__default_guardsize, guard);
	__release_ptc();

	return 0;
}

int pthread_getattr_default_np(pthread_attr_t *attrp)
{
	__acquire_ptc();
	*attrp = (pthread_attr_t) {
		._a_stacksize = __default_stacksize,
		._a_guardsize = __default_guardsize,
	};
	__release_ptc();
	return 0;
}
