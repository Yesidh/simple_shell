#include "holberton.h"
/**
 * _getenv2 - search for environment variable, and extract the PATH variable
 * This PATH variable contains all the directories where the shell will be able
 * to find a program to use as a child process the shell or as a built-in.
 *
 * @name: variable name for search
 * @stringpath: where the path will be save
 * @env: pointer to an array for environ variable
 *
 * Return: -1 on failure, 1 on ok and 0 on execution
 */
int _getenv2(const char *name, char *stringpath, char **env)
{
	size_t i = 0, j = 0;
	size_t lenghpath = 0;

	if ((name == NULL) || (env == NULL))
		return (-1);
	while (env[i] != NULL)
	{
		if (env[i][j] == name[j])
		{
			for (j = 1; name[j] != '\0';)
			{
				if (name[j] == env[i][j])
					j++;
			}
			if (name[j] == '\0')
			{
				for (j = 0; env[i][j] != '\0'; lenghpath++, j++)
					;
				_strncpy(stringpath, env[i]);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
