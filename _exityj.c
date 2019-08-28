#include "holberton.h"
/**
 * _exit - exit the shell
	 *
 * Return: nothing
 */
void _exityj(char **line)
{
	if (*line)
		free(*line);
	exit(98);
}
