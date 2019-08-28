#include "holberton.h"
/**
 * _strncpy - copies a string using pointers
 * @dest: destinations pointer
 * @src: source pointer
 *
 * Return: nothing
 */
int _strncpy(char *dest, char *src)
{
	int increment = 0;

	if ((dest == NULL) || (src == NULL))
		return (-1);
	while (*(src + increment) != '\0')
	{
		*(dest + increment) = *(src + increment);
		++increment;
	}
	*(dest + increment) = *(src + increment);
	return (0);
}
