#include "holberton.h"
/**
 * worker - funtion for execute a command
 * @stringconcat: command directory
 * @tokenscommand: arguments array command
 *
 * Return: always 1
 */
int worker(char *stringconcat, char **tokenscommand)
{
	pid_t pid, ppid, pidclosed, childpidstatus;

	ppid = getppid();
	pid = fork();
	if (pid < 0)
		perror("fork failure\n");
	if (pid == 0)
	{
		execve(stringconcat, tokenscommand, NULL);
		exit(5);
	}
	if (pid > 0)
		pidclosed = wait(NULL);
	return (0);
}
