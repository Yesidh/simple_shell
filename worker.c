#include "holberton.h"
/**
 * worker - funtion for execute a command
 * @stringconcat: command directory
 * @tokenscommand: arguments array command
 * @commandstring: strings of commands
 * @env: environ double pointer variable
 * Return: always 1
 */
int worker(char *stringconcat, char **tokenscommand, char *commandstring,
	   char **env)
{
	pid_t pid;
	size_t cont = 0;

	if ((tokenscommand == NULL) || (stringconcat == NULL) || (env == NULL))
		return (-1);
	pid = fork();
	if (pid < 0)
		perror("fork failure\n");
	if (pid == 0)
	{
		if (execve(stringconcat, tokenscommand, env) == -1)
		{
			if (commandstring)
				free(commandstring);
			return (0);
		}
		else
		{
			cont++;
			write(STDIN_FILENO, "command not found", 17);
			if (commandstring)
				free(commandstring);
			return (cont);
	}
	}
	if (pid > 0)
		wait(NULL);
	return (0);
}
