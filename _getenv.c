#include "holberton.h"

/**
 * _getenv - search for enviroment variable
 * @name: variable name for search
 * Return: a pointer to enviroment variable.
 */
char *_getenv(const char *name)
{
	size_t i = 0, j = 0, k = 0;
	size_t lenghpath = 0;
	extern char **environ;
	char *route;

	while (environ[i] != NULL)
	{
		if (environ[i][j] == name[j])
		{
			for (j = 1; name[j] != '\0';)
			{
				if (name[j] == environ[i][j])
					j++;
			}
			if (name[j] == '\0')
			{
				for (j = 0; environ[i][j] != '\0'; lenghpath++, j++)
					;
				route = (char *)malloc(sizeof(char) * (j +1));
				route = environ[i];
				for (k = 1; route[k - 1] != '='; k++)
					;
				return(route + k);
			}
		}
		i++;
	}
	return (0);
}
