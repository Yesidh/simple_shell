#include "holberton.h"
/**
 * _exityj - exit the shell. this command is a basic implementation to exit
 * the shell with a special command and not using ctrD or EOF. it does not
 * finish the shell taking into account the status of the exit state.
 *
 * @line: line write into the prompt
 *
 * Return: nothing
 */
void _exityj(char **line)
{
	if (*line)
		free(*line);
	exit(0);
}
