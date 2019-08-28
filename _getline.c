#include "holberton.h"
#include <termios.h>
/**
 * _getline - custom implementation of getline
 *
 * Return: -1 for ctr c, -2 for ctrd
 */
char *_getline(void)
{
	ssize_t res = 0;
	size_t bufsize = 0;
	int i = 0;
	char *buf = NULL;

	signal(SIGINT, _sigint_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "$ ", 2);
		res = getline(&buf, &bufsize, stdin);
		if (res == EOF)
		{
			if (buf)
				free(buf);
			write(STDIN_FILENO, "\n", 1);
			exit(0);
		}
		if (buf[0] != '\n')
		{
			for (i = 0; buf[i] != '\0'; i++)
			{
				if (buf[i] == '\n')
					return (buf);
			}
		}
		else
		{
			continue;
		}
		signal(SIGINT, _sigint_handler);
		res = getline(&buf, &bufsize, stdin);
		if (res == EOF)
		{
			if (buf)
				free(buf);
			write(STDIN_FILENO, "\n", 1);
			exit(0);
		}
	}
	if (res == EOF)
	{
		write(STDIN_FILENO, "\n", 1);
		exit(0);
	}
	if (buf)
		free(buf);
	return (NULL);
}
