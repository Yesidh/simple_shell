#include "holberton.h"
/**
 * simonbolivar - function for free a double pointer
 * @lancero: double pointer for free
 * Return: always 0
 */
int simonbolivar(char **lancero)
{
	size_t i = 0;

	while (lancero[i] != NULL)
	{
		if (lancero[i] != NULL)
			free(lancero[i]);	
		i++;
	}
	if (lancero)
		free(lancero);
	return (0);
}
