#include "holberton.h"
/**
 * _exityj - exit the shell
 * @line: line write into the promp
 * Return: nothing
 */
void _exityj(char **line)
{
	if (*line)
		free(*line);
	exit(0);
}
