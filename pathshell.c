#include "holberton.h"
int main (void)
{
	char *commandstring;
	char **tokenscommand;
	char **tokenspath;
	char *stringpath;
	char *stringconcat;
	int  flag = 0;


	while (flag != EOF)
	{
		commandstring = lineget();
		if (commandstring[0] != '/')
		{
			tokenscommand = tokenize(commandstring, " \n");
			stringpath = _getenv("PATH");
			tokenspath = tokenize(stringpath, ":\n");
			stringconcat = concatenatokens(tokenscommand, tokenspath);
		      	worker(stringconcat, tokenscommand);
		}
		else
		{
			tokenscommand = tokenize(commandstring, " \n");
			worker(tokenscommand[0], tokenscommand);
		}
	
	}
	return (0);
}
