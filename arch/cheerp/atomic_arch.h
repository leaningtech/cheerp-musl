#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
	return __sync_val_compare_and_swap_4(p, t, s);
//	__asm__ __volatile__ (
//		"lock ; cmpxchg %3, %1"
//		: "=a"(t), "=m"(*p) : "a"(t), "r"(s) : "memory" );
}

#define a_swap a_swap
static inline int a_swap(volatile int *p, int v)
{
	return __sync_swap(p, v);
//	__asm__ __volatile__(
//		"xchg %0, %1"
//		: "=r"(v), "=m"(*p) : "0"(v) : "memory" );
}

#define a_fetch_add a_fetch_add
static inline int a_fetch_add(volatile int *p, int v)
{
	return __sync_fetch_and_add(p, v);
//	__asm__ __volatile__(
//		"lock ; xadd %0, %1"
//		: "=r"(v), "=m"(*p) : "0"(v) : "memory" );
}

#define a_and a_and
static inline void a_and(volatile int *p, int v)
{
	__sync_and_and_fetch(p, v);
//	__asm__ __volatile__(
//		"lock ; and %1, %0"
//		: "=m"(*p) : "r"(v) : "memory" );
}

#define a_or a_or
static inline void a_or(volatile int *p, int v)
{
	__sync_or_and_fetch(p, v);
//	__asm__ __volatile__(
//		"lock ; or %1, %0"
//		: "=m"(*p) : "r"(v) : "memory" );
}

#define a_inc a_inc
static inline void a_inc(volatile int *p)
{
	__sync_add_and_fetch(p, 1);
//	__asm__ __volatile__(
//		"lock ; incl %0"
//		: "=m"(*p) : "m"(*p) : "memory" );
}

#define a_dec a_dec
static inline void a_dec(volatile int *p)
{
	__sync_add_and_fetch(p, -1);
//	__asm__ __volatile__(
//		"lock ; decl %0"
//		: "=m"(*p) : "m"(*p) : "memory" );
}

#define a_store a_store
static inline void a_store(volatile int *p, int x)
{
	__atomic_store(p, &x, __ATOMIC_SEQ_CST);
//	__asm__ __volatile__(
//		"mov %1, %0 ; lock ; orl $0,(%%esp)"
//		: "=m"(*p) : "r"(x) : "memory" );
}

static inline _Noreturn void unreachable()
{
	__builtin_unreachable();
}

#define a_barrier a_barrier
static inline void a_barrier()
{
//	__asm__ __volatile__( "" : : : "memory" );
}

#define a_spin a_spin
static inline void a_spin()
{
//	__asm__ __volatile__( "pause" : : : "memory" );
}

#define a_crash a_crash
static inline void a_crash()
{
	unreachable();
//	__asm__ __volatile__( "hlt" : : : "memory" );
}

#define a_ctz_64 a_ctz_64
static inline int a_ctz_64(uint64_t x)
{
	if (x == 0)
		return 64;
	return __builtin_ctzll(x);
//	int r;
//	__asm__( "bsf %1,%0 ; jnz 1f ; bsf %2,%0 ; add $32,%0\n1:"
//		: "=&r"(r) : "r"((unsigned)x), "r"((unsigned)(x>>32)) );
//	return r;
}

#define a_ctz_32 a_ctz_32
static inline int a_ctz_32(uint32_t x)
{
	if (x == 0)
		return 32;
	return __builtin_ctzl(x);
//	int r;
//	__asm__( "bsf %1,%0" : "=r"(r) : "r"(x) );
//	return r;
}

#define a_clz_32 a_clz_32
static inline int a_clz_32(uint32_t x)
{
	return __builtin_clz(x);
//	__asm__( "bsr %1,%0 ; xor $31,%0" : "=r"(x) : "r"(x) );
	return x;
}
