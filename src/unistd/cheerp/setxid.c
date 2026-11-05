#include <errno.h>
#include "libc.h"

// NOTE: SYS_* name the syscall entry functions here, which nr cannot carry
int __setxid(int nr, int id, int eid, int sid)
{
	errno = EPERM;
	return -1;
}
