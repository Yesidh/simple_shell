#include "holberton.h"
/**
 * _getenv - search for enviroment variable
 * @name: variable name for search
 * Return: a pointer to enviroment variable.
 */
extern char** environ;
void _getenv2(const char *name, char *stringpath)
{
	size_t i = 0, j = 0, k = 0;
	size_t lenghpath = 0;
	char **envloc = environ;
	char *route = NULL;

	while (envloc[i] != NULL)
	{
		if (envloc[i][j] == name[j])
		{
			for (j = 1; name[j] != '\0';)
			{
				if (name[j] == envloc[i][j])
					j++;
			}
			if (name[j] == '\0')
			{
				for (j = 0; envloc[i][j] != '\0'; lenghpath++, j++)
					;
				route = (char *)malloc(sizeof(char) * (j + 1));
				route = envloc[i];
				for (k = 1; route[k - 1] != '='; k++)
					;
				stringpath = route + k;
				return;
			}
		}
		i++;
	}
	return;
}
