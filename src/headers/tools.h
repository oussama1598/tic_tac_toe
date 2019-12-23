#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_file(char *filename, char **file_content);
char *join_strings(char *str1, char *str2);
int count_occurence(char *str, char delimiter);
int split(char *str, char *delimiter, char ***result);

#endif
