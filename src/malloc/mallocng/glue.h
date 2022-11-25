#ifndef MALLOC_GLUE_H
#define MALLOC_GLUE_H

#include <stdint.h>
#include <sys/mman.h>
#include <pthread.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include "atomic.h"
#include "syscall.h"
#include "libc.h"
#include "lock.h"
#include "dynlink.h"

// use macros to appropriately namespace these.
#define size_classes __malloc_size_classes
#define ctx __malloc_context
#define alloc_meta __malloc_alloc_meta
#define is_allzero __malloc_allzerop
#define dump_heap __dump_heap

#ifndef __CHEERP__
#define malloc __libc_malloc_impl
#define realloc __libc_realloc
#define free __libc_free
#endif

#define USE_MADV_FREE 0

#if USE_REAL_ASSERT
#include <assert.h>
#else
#undef assert
#define assert(x) do { if (!(x)) a_crash(); } while(0)
#endif

#define brk(p) ((uintptr_t)__syscall(SYS_brk, p))

#define mmap __mmap
#define madvise __madvise
#define mremap __mremap

#define DISABLE_ALIGNED_ALLOC (__malloc_replaced && !__aligned_alloc_replaced)

#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
static inline uint64_t get_random_secret()
{
	return 6148914691236517205UL; // represented in binary as alternating 0 and 1.
}

#ifndef PAGESIZE
#define PAGESIZE PAGE_SIZE
#endif

#if defined(__CHEERP__) && !defined(__ASMJS__)
#define MT (0)
#else
#define MT (libc.need_locks)
#endif

#define RDLOCK_IS_EXCLUSIVE 1

__attribute__((__visibility__("hidden")))
#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
extern int __malloc_lock[1];

#define LOCK_OBJ_DEF \
int __malloc_lock[1]; \
void __malloc_atfork(int who) { malloc_atfork(who); }

#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
static inline void rdlock()
{
	if (MT) LOCK(__malloc_lock);
}
#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
static inline void wrlock()
{
	if (MT) LOCK(__malloc_lock);
}
#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
static inline void unlock()
{
	UNLOCK(__malloc_lock);
}
#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
static inline void upgradelock()
{
}
#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
static inline void resetlock()
{
	__malloc_lock[0] = 0;
}

#ifdef __CHEERP__
__attribute__((cheerp_asmjs))
#endif
static inline void malloc_atfork(int who)
{
	if (who<0) rdlock();
	else if (who>0) resetlock();
	else unlock();
}

#endif
