#include "holberton.h"
int main (void)
{
	char *commandstring = NULL;
	char *tokenscommand[50] = { 0 };
	char *tokenspath[50] = { 0 };
	char stringpath[512];
	char stringconcat[120];
	/* size_t linesize = 0; */
	int  flag = 0;
	while (1)
	{
		flag = 0;
		commandstring = _getline();
		tokenize2(commandstring, tokenscommand, " \n");
		if (tokenscommand[0][0] != '/')
		{
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
					if(concatenatokens(tokenscommand, tokenspath, stringconcat) == 1)
						worker(stringconcat, tokenscommand, commandstring);
				}
			}
		}
		else
		{
			/* tokenize2(commandstring, tokenscommand, " \n"); */
			if (tokenscommand[0])
				worker(tokenscommand[0], tokenscommand, commandstring);
		}
		/* if (stringconcat) */
		/* 	free(stringconcat); */
		 if (commandstring) 
		 	free(commandstring); 
	}
	return (0);
}
