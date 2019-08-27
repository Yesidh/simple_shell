#include "holberton.h"
/**
 * _exit - exit the shell
	 *
 * Return: nothing
 */
void _exityj(char **line, char **tokenscommand)
{
	int i = 0;
	if (*line)
		free(*line);
	while(tokenscommand[i])
	{
		free(tokenscommand[i]);
		i++;
	}
	free(tokenscommand);
	exit(98);
}
