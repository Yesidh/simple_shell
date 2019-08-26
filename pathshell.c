#include "holberton.h"
int main (void)
{
        char  *pathargs;
	char *commandstring;
	char **tokenscommand;
	char **tokenspath;
	char *stringpath;
	char *stringconcat;
	unsigned int i, j, k;
	ssize_t r;
	pid_t pid, ppid, pidclosed, childpidstatus;
	int status = 0, flag = 0;


	while (flag != EOF)
	{
		commandstring = lineget();
		if (commandstring[0] != '/')
		{
			tokenscommand = tokenize(commandstring, " \n");
			i = 0;
			while (tokenscommand[i] != '\0')
			{
				printf("tokencommand[%d]: %s\n",i, tokenscommand[i]);
				i++;
			}
			stringpath = _getenv("PATH");
			printf("%s\n", stringpath);
			tokenspath = tokenize(stringpath, ":\n");
			i = 0;
			while (tokenspath[i] != '\0')
			{
				printf("pathtoken[%u]: %s\n", i, tokenspath[i]);
				i++;
			}
			stringconcat = concatenatokens(tokenscommand, tokenspath);
			printf("tokens: %s\n", stringconcat);
			worker(stringconcat, tokenscommand);
		}
	}
	return (0);
}
