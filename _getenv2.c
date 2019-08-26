#include <stdio.h>

/**
 * main - search for enviroment variable
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	unsigned int i, j = 0;
	char envariable [6] = "PATH=";
	i = 0;

	while (env[i] != NULL)
	{
		if (env[i][j] == envariable[j])
		{
			for (j = 1; envariable[j] != '\0';)
			{
				if (envariable[j] == env[i][j])
					j++;
			}
			if (envariable[j] == '\0')
				printf("%s\n", env[i]);
		}
		i++;
	}
	return (0);
}
