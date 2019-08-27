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
	size_t i = 0, j = 0, k = 0, tok = 0;
	size_t lenghstring = 0, flag = 0, lenghtoken = 0;

	for (i = 0; stringtotokens[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (stringtotokens[i] == delim[j])
				k++;
		}
	}
	lenghstring = i;
	tokens = (char **)malloc(sizeof(char *) * (k + 1));
	if (tokens == NULL)
	{
		perror("Can't alloc memory in tokenize function");
		exit(-1);
	}
	for (i = 0; stringtotokens[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
 		{
			if (stringtotokens[i] == delim[j])
			{
				flag = 1;
				break;
			}
		}
		if ( flag == 1)
			break;
	}
	lenghtoken = i;
	tokens[0] = malloc(sizeof(char) * i);
	if (tokens[0] == NULL)
	{
		perror("cant' alloc memory into tokens");
		exit(-1);
	}
	tokens[k] = NULL;
	tokens[tok] = strtok(stringtotokens, delim);
	while (tok < k)
	{
		flag = 0;
		lenghtoken++;
		tok++;
		i = 0;
		for (; stringtotokens[lenghtoken] != '\0'; i++, lenghtoken++)
		{
			for (j = 0; delim[j] != '\0'; j++)
			{
				if (stringtotokens[lenghtoken] == delim[j])
				{
					flag = 1;
					break;
				}
			}
			if ( flag == 1)
				break;
		}
		tokens[tok] = malloc(sizeof(char) * i);
		if (tokens[tok] == NULL)
		{
			perror("can't alloc memory into tokens");
			exit(-1);
		}
		tokens[tok] = strtok(NULL, delim);
		if (tokens[tok] == NULL)
			break;
	}
	return (tokens);
}
