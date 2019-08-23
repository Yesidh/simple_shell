#include "holberton.h"
int main (void)
{
        char *buf, *args, *pathargs;
	char copiastring[1024] = { 0 }, delim [] = " \n";
        char *tokens[10] = { NULL };
	char *pathtokens[10] = { NULL };
	char *stringpath = { 0 }, pathdelim [] = ":\n";
	char *stringconcat = { 0 };
	size_t bufsize;
	unsigned int i, j, k;
	ssize_t r;
	pid_t pid, ppid, pidclosed, childpidstatus;
	int status = 0, flag = 0;
	struct stat st;


/*getline*/
	while (flag != EOF)
	{
		buf = NULL;
		bufsize = 0;
		printf("#usandoPATH$ ");
		r = getline(&buf, &bufsize, stdin);
		if (r == -1)
		{
			free(buf);
			perror("No se puede copiar la entrada\n");
			exit(4);
		}
		strncpy(copiastring, buf, sizeof(copiastring));
		if (copiastring[0] != '/')
		{
			tokens[0] = strtok(copiastring, delim);
			i = 1;
			while (i < 10)
			{
				args = strtok(NULL, delim);
				if (args == NULL)
					break;
				tokens[i] = args;
				i++;
			}
			for (i = 0; i < 10; i++)
				printf("token[%u]: %s\n", i, tokens[i]);
/*stat*/
			stringpath = _getenv("PATH");
			printf("%s\n", stringpath);
			i = 0;
			pathtokens[0] = strtok(stringpath, pathdelim);
			i = 1;
			while (i < 10)
			{
				pathargs = strtok(NULL, pathdelim);
				if (pathargs == NULL)
					break;
				pathtokens[i] = pathargs;
				i++;
			}
			for (i = 0; i < 10; i++)
				printf("pathtoken[%u]: %s\n", i, pathtokens[i]);
			i = 0;
			while (pathtokens[i])
			{
				stringconcat = concatenatokens(tokens, pathtokens);
				printf("tokens: %s\n", stringconcat);
				
				if (stat(stringconcat, &st) == 0)
					printf(" FOUND\n");
				else
					printf(" NOT FOUND\n");
				i++;
				for (j = 0; j <= 1024; j++)
					stringconcat[j] = 0;
			}
		}



/*fork()
		ppid = getppid();
		pid = fork();
		printf("PPID %d\n", ppid);
		printf("PID created by fork: %u\n", pid);
		if (pid < 0)
			perror("fork failure\n");
		printf("antes del if del execute\n");
		if (pid == 0)
		{
			sleep(3);
			printf("estoy en el hijo\n");
			execv(tokens[0], tokens);
			exit(5);
		}
		memset(copiastring, 0, sizeof(copiastring));
		printf("estado del copiastring %s\n", copiastring);
		for (i = 0; i < 10; i++)
			tokens[i] = NULL;
		childpidstatus = WEXITSTATUS(status);
		if (pid > 0)
		{
			pidclosed = wait(NULL);
			printf("estoy en el padre %d y se ha cerrado el hijo %d\n", ppid, pidclosed);
			printf("valor de retorno del hijo %d\n", childpidstatus);
			}*/
	free(buf);
	}
	return (0);
}
