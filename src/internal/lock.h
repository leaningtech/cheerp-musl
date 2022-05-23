#ifndef LOCK_H
#define LOCK_H

hidden void __lock(volatile int *);
hidden void __unlock(volatile int *);

#define LOCK(x) (x)
#define UNLOCK(x) (x)

#endif
