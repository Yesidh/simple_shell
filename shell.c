#include "holberton.h"
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
	int *flag = 0;
	int res;
	char c;
	char *stringpath;
	char **tokenspath;
	char *stringconcat = { 0 };
	char **tokenscommand;

	while (1)
	{
		line  = _getline(flag);

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
				_env();

			if (!strncmp(tokens[0], "exit", 4) && !tokens[1])
			{
				_exityj(&line);
			}

			if (line[0] != '/')
			{

			stringpath = _getenv("PATH");
			tokenspath = tokenize(stringpath, ":\n");
			tokenscommand = tokenize(line, " \n");
			i = 0;

			stringconcat = concatenatokens(tokenscommand, tokenspath);

			tokens[0] = stringconcat;

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

			if (*flag == 1)
				break;
		}
	}

	if (line != NULL) {
		free(line);
	}
	return(0);
}
