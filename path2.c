#include "holberton.h"
int main (void)
{
	char *commandstring = NULL;
	char *tokenscommand[50] = { 0 };
	char *tokenspath[50] = { 0 };
	char stringpath[512];
	char *stringconcat = NULL;
	int  flag = 0;
	while (1)
	{
		flag = 0;
		commandstring = _getline();
		if (commandstring[0] != '/')
		{
			tokenize2(commandstring, tokenscommand, " \n");
			if ((_strcmp(tokenscommand[0], "env") == 0) && !tokenscommand[1])
			{
				_env();
				flag = 1;
			}
			if ((_strcmp(tokenscommand[0], "exit") == 0) && !tokenscommand[1])
			{
				_exityj(&commandstring);
				flag = 1;
			}
			if (flag != 1)
			{
				_getenv2("PATH", stringpath);
				tokenize2(stringpath, tokenspath, ":\n");
				if (tokenspath[0])
				{
					stringconcat = concatenatokens(tokenscommand, tokenspath);
					worker(stringconcat, tokenscommand, commandstring);
				}
			}
		}
		else
		{
			tokenize2(commandstring, tokenscommand, " \n");
			if (tokenscommand[0])
				worker(tokenscommand[0], tokenscommand, commandstring);
		}
		if (stringconcat)
			free(stringconcat);
		if (commandstring)
			free(commandstring);
	}
	return (0);
}
