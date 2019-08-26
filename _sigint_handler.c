#include "holberton.h"
void _sigint_handler(int sig)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		write(STDIN_FILENO, &sig, sizeof(sig));
}
