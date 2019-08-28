#include "holberton.h"
/**
 * tokenize - function to tokenizer an string
 * @stringtotokens: string for tokenizer
 * @delim: delimiters for tokenization
 *
 * Return: a pointer with the tokenization
 */
void tokenize2(char *stringtotokens, char **tokenspath, char *delim)
{
	size_t i = 0;

	tokenspath[i] = strtok(stringtotokens, delim);

	while (i < 50)
	{
		i++;
		tokenspath[i] = strtok(NULL, delim);
		if (i == 49 || tokenspath[i] == NULL)
			break;
	}
}
