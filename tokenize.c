#include "holberton.h"
/**
 * tokenize - function to tokenizer an string
 * @stringtotokens: string for tokenizer
 * @delim: delimiters for tokenization
 *
 * Return: a pointer with the tokenization
 */
char **tokenize(char *stringtotokens, const char *delim)
{
	char **tokens;
	size_t i;

	for (i = 0; stringtotokens[i]; i++)
		;
	tokens = malloc((i) * sizeof(char));
	if (tokens == NULL)
	{
		perror("Can't alloc memory in tokenize function");
		exit(-1);
	}
	tokens[0] = strtok(stringtotokens, delim);
	i = 1;
	while (tokens[i])
	{
		tokens[i] = strtok(NULL, delim);
		if (tokens[i] == '\0')
			break;
		i++;
	}
	return (tokens);
}
