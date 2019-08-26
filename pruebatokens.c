#include "holberton.h"
/**
 * funcion prueba tokens
 */
int main(void)
{
	char cadena[] = "probando los tokens";
	char delimitador[] = " \n";
	char *token;
	int i, j, k, flag = 0;

	for (i = 0; cadena[i]; i++)
	{
		for (j = 0; delimitador[j]; j++)
		{
			if (cadena[i] == delimitador[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	k = i;
	printf(" main los caracteres del primer tokens son: %d\n", i);
	token = strtok(cadena, delimitador);
	while (token != NULL)
	{
		flag = 0;
		i = 0;
		k++;
		printf("token %s\n", token);
		for (; cadena[k] != '\0'; k++, i++)
		{
			for (j = 0; delimitador[j]; j++)
			{
				if (cadena[k] == delimitador[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		printf(" while los caracteres del primer tokens son: %d\n", i);
		token = strtok(NULL, delimitador);
	}
	return (0);
}
