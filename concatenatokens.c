#include "holberton.h"
/**
 * concatenatokens - function for concatenates two tokens
 * @tokenscommand: pointer to command token
 * @tokenspath: pointer to tokens of the PATH
 * @stringconcat: pointer where concatenate string will be save
 * Return: a pointer to concatenate string
 */
int concatenatokens(char **tokenscommand, char **tokenspath,
		    char *stringconcat)
{
	size_t j = 0, k = 0, l = 0;
	struct stat st;

	if ((tokenscommand == NULL) || (tokenspath == NULL))
		return (-1);
	for (j = 0; tokenspath[j] != NULL; j++)
	{
		for (k = 0; tokenspath[j][k] != '\0'; k++)
			stringconcat[k] = tokenspath[j][k];
		stringconcat[k] = '/';
		k++;
		for (l = 0; tokenscommand[0][l] != '\0'; l++, k++)
			stringconcat[k] = tokenscommand[0][l];
		stringconcat[k] = '\0';
		if (stat(stringconcat, &st) == 0)
			return (1);
	}
	return (0);
}
