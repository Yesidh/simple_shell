#include "holberton.h"
extern char **environ;
/**
 * main - read commands with their full path
 *
 *
 *
 *
 * Return: always 0
 */
int main(void)
{
	char *line = NULL;
	pid_t child_pid;
	int status = 1, i;
	char *tokens[256] = {NULL};
	char **envloc = environ;
	int flag = 0;
	int res;
	char c;
	char *envlist[256] = {NULL};

	while (1)
	{
		line  = _getline();

		if (line == "controlD")
			return (0);

		while(tokens[i])
		{
			tokens[i] = NULL;
			i++;
		}

		i = 0;

		if (line)
		{
			for (char *token = strtok(line, DELIM);
			     token; token = strtok(NULL, DELIM))
			{
				tokens[i] = token;
				if (i == 255)
					break;
				i++;
			}

			tokens[i + 1] = NULL;

			i = 0;

			if ((strcmp(tokens[0], "env") == 0)  && !tokens[1])
			{
				for(i = 0; envloc[i] != NULL; i++)
				{
					write(STDIN_FILENO, envloc[i], _strlen(envloc[i] + 1));
					write(STDIN_FILENO, "\n", 1);
				}
			}

			if (!strncmp(tokens[0], "exit", 4) && !tokens[1])
			{
				flag = 2;
				if (line)
					free(line);
				return(0);
			}
			child_pid = fork();
			if (child_pid == -1) {
				printf("error al crear el child");
				return (1);
			}
			if (child_pid == 0) {
				if (execve(tokens[0], tokens, NULL) == -1) {
					if (line)
						free(line);
					return (0);
				} else
				{
					write(STDIN_FILENO, "command not found", 17);
				}
			} else {
				wait(&status);
			}
		}
	}

	if (line != NULL) {
		free(line);
	}
	return(0);
}
