#include "holberton.h"
/**
 * _exit - exit the shell
	 *
 * Return: nothing
 */
void _exityj(char **line)
{
	int i = 0;
	if (*line)
		free(*line);
	exit(98);
}
