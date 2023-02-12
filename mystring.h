#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>
#include <stdio.h>

size_t mystrlen(const char *s);
char *mystrdup(const char *str);
char *mystrtok(char *buf, char *delim);
void mymemcpy(char *str2, char *str1, size_t n);
char *myreadline(char *prompt);

#endif

