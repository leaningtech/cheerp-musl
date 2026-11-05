# Generates bits/syscall.h from a syscall list (first file) and a header template (second file).
# Each list entry is __SYSCALL_DEF(name, number, params...); each template line that is one of
# these markers expands to a line per entry:
#   @NR@          #define __NR_name number
#   @SYS_NR@      #define SYS_name number
#   @SYS_ENTRY@   #define SYS_name __syscall_name

BEGIN { n = 0 }

FNR == NR {
	if (match($0, /^__SYSCALL_DEF\([a-z0-9_]+, *[0-9]+/)) {
		split(substr($0, 15, RLENGTH - 14), f, /, */)
		name[n] = f[1]
		nr[n++] = f[2]
	}
	next
}

$0 == "@NR@" { for (i = 0; i < n; i++) print "#define __NR_" name[i] " " nr[i]; next }
$0 == "@SYS_NR@" { for (i = 0; i < n; i++) print "#define SYS_" name[i] " " nr[i]; next }
$0 == "@SYS_ENTRY@" { for (i = 0; i < n; i++) print "#define SYS_" name[i] " __syscall_" name[i]; next }
{ print }
