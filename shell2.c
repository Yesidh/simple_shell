#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#define DELIM " \n"
#define PROMPT "#cisfun$ "
#include<signal.h>
extern char **environ;
/**
 * main - read commands with their full path
 *
 *
 *
 *
 * Return: always 0
 */
volatile sig_atomic_t sigint_received = 0;

void sigint_handler(int s)
{
	sigint_received = 1;
}

int main(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	pid_t child_pid;
	int status = 1, i;
	char *tokens[256] = {NULL};
	char **envloc = environ;
	int flag = 0;
	int res;
	char c;
	

	while (1)
	{
		flag = 0;
		write(STDIN_FILENO, PROMPT, 9);

		res = getline(&buf, &bufsize, stdin);

		c = getchar();
		if (c == EOF)
			break;

		if (res == -1)
		{
			write(STDIN_FILENO, "\n", 1);
			return (0);
		}
		i = 0;
		while(tokens[i])
		{
			tokens[i] = NULL;
			i++;
		}

		i = 0;

		if (buf)
		{
			for (char *token = strtok(buf, DELIM);
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
				flag = 1;
				for(i = 0; envloc[i] != NULL; i++)
				{
					write(STDIN_FILENO, envloc[i], sizeof(int));
					write(STDIN_FILENO, "\n", 1);
				}
			}

			if (!strncmp(tokens[0], "exit", 4) && !tokens[1])
			{
				flag = 2;
				if (buf)
					free(buf);
				return(0);
			}
			if (flag == 0) {

				child_pid = fork();
				if (child_pid == -1) {
					printf("error al crear el child");
					return (1);
				}
				if (child_pid == 0) {
					if (execve(tokens[0], tokens, NULL) == -1) {
						if (buf)
							free(buf);
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
	}
	
	if (buf != NULL) {
		free(buf);
	}
	return(0);
}
