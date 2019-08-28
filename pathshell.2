#include "holberton.h"
int main (void)
{
	char *commandstring = NULL;
	char **tokenscommand = NULL;
	char **tokenspath = NULL;
	char *stringpath = NULL;
	char *stringconcat = NULL;
	int  flag = 0;
	int i = 0;

	while (flag != EOF)
	{
		flag = 0;

		commandstring = _getline();
		if (commandstring[0] != '/')
		{
			tokenscommand = tokenize(commandstring, " \n");
			if ((_strcmp(tokenscommand[0], "env") == 0) && !tokenscommand[1])
			{
				_env();
				flag = 1;
			}
			if ((_strcmp(tokenscommand[0], "exit") == 0) && !tokenscommand[1])
			{
				_exityj(&commandstring, tokenscommand);
				flag = 1;
			}
			if (flag != 1)
			{
				stringpath = _getenv("PATH");
				tokenspath = tokenize(stringpath, ":\n");
				stringconcat = concatenatokens(tokenscommand, tokenspath);
				worker(stringconcat, tokenscommand);
			}
		}
		else
		{
			tokenscommand = tokenize(commandstring, " \n");
			worker(tokenscommand[0], tokenscommand);
		}
		i = 0;
		while(tokenscommand[i])
		{
			free(tokenscommand[i]);
			i++;
		}
		if (tokenscommand)
			free(tokenscommand);
		i = 0;
		while(tokenspath[i])
		{
		 	free(tokenspath[i]);
		 	i++;
		 }
		if (tokenspath)
			free(tokenspath);
		if (commandstring)
			free(commandstring);
		if (stringconcat)
			free(stringconcat);
		if (stringpath)
			free(stringpath);
	}
	return (0);
}
