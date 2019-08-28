#include "holberton.h"
/**
 * main - simple shell project
 * @ac: arguments numbers
 * @av: pointer to arguments arrays
 * @env: environ variable
 * Return: 0 on ok execution and -1 in error
*/
int main(int ac, char **av, char **env)
{
	char *commandstring = NULL;
	char *tokenscommand[50] = { 0 };
	char *tokenspath[50] = { 0 };
	char stringpath[512];
	char stringconcat[120];
	int  flag = 0;
	pid_t pid = 0;
	(void) ac;
	(void) av;

	while (1)
	{
		if (pid == -1)
		{
			perror("Error:");
			exit(0);
		}
		flag = 0;
		commandstring = _getline();
		tokenize2(commandstring, tokenscommand, " \n\t");
		if (tokenscommand[0] && tokenscommand[0][0] != '/')
		{
			if ((_strcmp(tokenscommand[0], "env") == 0) && !tokenscommand[1])
			{
				_env(env);
				flag = 1;
			}
			if ((_strcmp(tokenscommand[0], "exit") == 0) && !tokenscommand[1])
			{
				_exityj(&commandstring);
				flag = 1;
			}
			if (flag != 1)
			{
				_getenv2("PATH", stringpath, env);
				tokenize2(stringpath, tokenspath, ":\n\t");
				if (tokenspath[0])
				{
					if (concatenatokens(tokenscommand, tokenspath, stringconcat) == 1)
						worker(stringconcat, tokenscommand, commandstring, env);
					else
						write(STDIN_FILENO, "command not found", 17);
				}
			}
		}
		else
		{
			if (tokenscommand[0])
				worker(tokenscommand[0], tokenscommand, commandstring, env);
		}
		if (commandstring)
		 	free(commandstring);
	}
	return (0);
}
