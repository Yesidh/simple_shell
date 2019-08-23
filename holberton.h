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
#endif
