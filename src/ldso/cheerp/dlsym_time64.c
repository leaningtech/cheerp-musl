void *__dlsym_redir_time64(void *restrict, const char *restrict, void *restrict);

__attribute__((__weak__))
void *__dlsym_time64(void *restrict p, const char *restrict s)
{
	return __dlsym_redir_time64(p, s, 0);
}
