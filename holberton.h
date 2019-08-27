#ifndef SIMPLESHELL
#define SIMPLESHELL
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#define DELIM " \n"
#define PROMPT "#cisfun$ "
#include<signal.h>
char *_getenv(const char *name);
char *concatenatokens(char **tokenscommand, char **tokenspath);
char *lineget(void);
char **tokenize(char *stringtokens, const char *delim);
int worker(char *stringconcat, char **tokenscomand);
ssize_t promptcycle(char *buf);
void _sigint_handler(int sig);
void _env(void);
void _exityj(char **);
int simonbolivar( char **lancero);
int _getchar(void);
char *_getline(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
#endif
