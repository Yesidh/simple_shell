#include "holberton.h"
/**
 * _sigint_handler - xxx
 *@sig: xx
 * Return: nothing
 */
void _sigint_handler(int sig)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		write(STDIN_FILENO, &sig, sizeof(sig));
}
