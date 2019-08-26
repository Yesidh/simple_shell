#include "holberton.h"
/**
 * concatenatokens - function for concatenates two tokens
 * @tokencommand: pointer to command token
 * @tokenpath: pointer to tokens of the PATH
 * Return: a pointer to concatenate string
 */
char *concatenatokens(char **tokenscommand, char **tokenspath)
{
	size_t j = 0, k = 0, l = 0;
	char *stringconcat;
	struct stat st;

	for (j = 0; tokenspath[j] != NULL; j++)
	{
		stringconcat = malloc(sizeof(char) * 120);

		for (k = 0; tokenspath[j][k] != '\0'; k++)
			stringconcat[k] = tokenspath[j][k];
		stringconcat[k] = '/';
		k++;
		for (l = 0; tokenscommand[0][l] != '\0'; l++, k++)
			stringconcat[k] = tokenscommand[0][l];
		stringconcat[k] = '\0';
		printf("concatenado es: %s\n", stringconcat);
		if (stat(stringconcat, &st) == 0)
			return(stringconcat);
		free(stringconcat);
	}
	return(0);
}
