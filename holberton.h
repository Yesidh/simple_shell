#ifndef SIMPLESHELL
#define SIMPLESHELL
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>
int concatenatokens(char **tokenscommand, char **tokenspath,
		    char *stringconcat);
int worker(char *stringconcat, char **tokenscomand, char *commandstring,
	   char **env);
void _sigint_handler(int sig);
void _env(char **env);
void _exityj(char **line);
int _getchar(void);
char *_getline(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void tokenize2(char *stringtotokens, char **tokenspath, char *);
int _getenv2(const char *name, char *stringpath, char **env);
int _strncpy(char *dest, char *src);
void mainaux(char *stringconcat, char **tokenspath, char *stringpath,
	     char *commandstring, char **tokenscommand, char **env);
#endif
