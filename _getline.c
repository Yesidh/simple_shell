#include "holberton.h"
#include <termios.h>
/**
 * _getline - custom implementation of getline
 *
 * Return: -1 for ctr c, -2 for ctrd
 */
/* reads from keypress, doesn't echo */
int getch(void)
{
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

char *_getline(void)
{
	ssize_t res = 0;
	ssize_t bufsize = 0;
	int i = 0;
	char *buf = NULL;
	char c;

	write(STDIN_FILENO, PROMPT, 9);
	signal(SIGINT, _sigint_handler);
	res = getline(&buf, &bufsize, stdin);


	while (1)
	{
		if (res == EOF)
		{
			if (buf)
				free(buf);
			write(STDIN_FILENO, "\n", 1);
			exit(98);
		}
		if (buf[0] != '\n')
		{
			for (i = 0; buf[i] != '\0'; i++)
			{
				if (buf[i] == '\n')
					return (buf);
			}
		}
		write(STDIN_FILENO, PROMPT, 9);
		signal(SIGINT, _sigint_handler);
		res = getline(&buf, &bufsize, stdin);

		if (res == EOF)
		{
			if (buf)
				free(buf);
			write(STDIN_FILENO, "\n", 1);
			exit(98);
		}
	}
	
	if (res == EOF)
	{
		write(STDIN_FILENO, "\n", 1);
		exit(98);
	}
	if (buf)
		free(buf);
	return (NULL);
}
