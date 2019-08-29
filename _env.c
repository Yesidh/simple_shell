#include "holberton.h"
/**
 * _env - prints the environment variable in the stdout.
 * it takes the environment information from the third argument
 * in the main function. It does not take the info from the extern variable
 * called environ because Betty does not allow it, although is possible.
 *
 * @env: environ variables
 *
 * Return: nothing
 */
void _env(char **env)
{
	int i;

	if (env == NULL)
		return;
	for (i = 0; env[i] != NULL; i++)
	{
		write(STDIN_FILENO, env[i], _strlen(env[i] + 1));
		write(STDIN_FILENO, "\n", 1);
	}
}
