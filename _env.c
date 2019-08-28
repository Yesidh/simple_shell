#include "holberton.h"
/**
 * _env - prints the environment variable in the stdout
 *
 * Return: nothing
 */
void _env(char **env)
{
	int i;

	for(i = 0; env[i] != NULL; i++)
	{
		write(STDIN_FILENO, env[i], _strlen(env[i] + 1));
		write(STDIN_FILENO, "\n", 1);
	}
}
