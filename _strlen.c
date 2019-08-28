#include "holberton.h"
/**
 * _strlen - returns the lenght of a string
 * @s: string to test
 *
 * Return: always len of string
 */
int _strlen(char *s)
{
	int increment = 0;

	if (s == NULL)
		return (-1);
	while (*(s + increment) != '\0')
	{
		increment++;
	}

	return (increment);
}
