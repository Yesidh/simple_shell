#include "holberton.h"
/**
 * concatenatokens - function for concatenates two tokens
 * @tokencommand: pointer to command token
 * @tokenpath: pointer to tokens of the PATH
 * Return: a pointer to concatenate string
 */
char *concatenatokens(char **tokencommand, char **tokenpath)
{
	unsigned int i, j;
	char *stringconcat = { 0 };

	for (; tokenpath != NULL;)
	{
		for (i = 1; tokenpath[i - 1] != NULL; i++)
			stringconcat[i] = tokenpath[i];
		stringconcat[i] = '/';
		for (j =1; tokencommand[j - 1] != NULL; j++, i++)
			stringconcat[i] = tokencommand[j];
	}
	return(stringconcat);
}
