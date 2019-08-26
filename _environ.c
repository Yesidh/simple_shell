#include <stdio.h>

/**
 * main - search for enviroment variable
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned int i, j = 0;
	char envariable [6] = "PATH=";
	extern char **environ;
	i = 0;

	while (environ[i] != NULL)
	{
		if (environ[i][j] == envariable[j])
		{
			for (j = 1; envariable[j] != '\0';)
			{
				if (envariable[j] == environ[i][j])
					j++;
			}
			if (envariable[j] == '\0')
				printf("%s\n", environ[i]);
		}
		i++;
	}
	return (0);
}
