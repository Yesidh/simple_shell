#include "holberton.h"
/**
 * _env - to print environmental variable
 *
 * Return: nothing
 */
extern char** environ;
void _env(void)
{
	char **envloc = environ;
	int i;

	for(i = 0; envloc[i] != NULL; i++)
	{
		write(STDIN_FILENO, envloc[i], _strlen(envloc[i] + 1));
		write(STDIN_FILENO, "\n", 1);
	}
}