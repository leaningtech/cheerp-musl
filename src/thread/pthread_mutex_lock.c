#include "pthread_impl.h"

void pushDebug(int nr);

int __pthread_mutex_lock(pthread_mutex_t *m)
{
	pushDebug(11111);
	pushDebug(m->_m_lock);
	m->_m_check += 1;
	if ((m->_m_type&15) == PTHREAD_MUTEX_NORMAL
	    && !a_cas(&m->_m_lock, 0, EBUSY))
	{
		pushDebug(m->_m_lock);
		pushDebug(1111111);
		return 0;
	}

	return __pthread_mutex_timedlock(m, 0);
}

weak_alias(__pthread_mutex_lock, pthread_mutex_lock);
