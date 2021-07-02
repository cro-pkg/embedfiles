#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char *concat(const char *s1, const char *s2);
void print_help(char *argv[]);
char * recover_filename(FILE * f);
#endif
