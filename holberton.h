#ifndef SIMPLESHELL
#define SIMPLESHELL

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>

char *_getenv(const char *name);
char *concatenatokens(char **tokenscommand, char **tokenspath);
char *lineget(void);
char **tokenize(char *stringtokens, const char *delim);
int worker(char *stringconcat, char **tokenscomand);
#endif
