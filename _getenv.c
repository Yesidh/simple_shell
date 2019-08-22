#include "holberton.h"

/**
 * _getenv - search for enviroment variable
 * @name: variable name for search
 * Return: a pointer to enviroment variable.
 */
char *_getenv(const char *name)
{
	unsigned int i, j, k;
	extern char **environ;
	char *route[1024] = { NULL };

	i = 0;
	j = 0;
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

				*route = environ[i];
				for (k = 0; route[0][k] != '='; k++)
					;
				k++;
				return(*route + k);
			}
		}
		i++;
	}
	return (0);
}
