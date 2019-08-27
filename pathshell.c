#include "holberton.h"
int main (void)
{
	char *commandstring;
	char **tokenscommand;
	char **tokenspath;
	char *stringpath;
	char *stringconcat;
	int flag = 0;
	int flagdoor = 0;

	while (flag != EOF)
	{
		flagdoor = 0;

		commandstring = _getline();
		if (commandstring[0] != '/')
		{
			tokenscommand = tokenize(commandstring, " \n");
			if ((_strcmp(tokenscommand[0], "env") == 0) && !tokenscommand[1])
			{
				_env();
				flagdoor = 1;
			}
			if ((_strcmp(tokenscommand[0], "exit") == 0) && !tokenscommand[1])
			{
				_exityj(&commandstring);
				flagdoor = 1;
			}
			if (flagdoor != 1)
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
	}
	return (0);
}
