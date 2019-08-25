#include "holberton.h"
/**
 *
 *
 *
 *
 */
char *lineget(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	ssize_t r;

	write(STDOUT_FILENO, "simpleshell$ ", 13);
	r = getline(&buf, &bufsize, stdin);
	if (r == -1)
	{
		perror("simpleshell$ : input error");
		free(buf);
		exit(2);
	}
	return (buf);
}
