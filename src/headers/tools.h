#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imports.h"

int load_file(char *filename, char **file_content);
void append_to_file(char *filename, char *data);
void update_first_instance_in_file_of_user(char *filename, char *data, char *username);
void remove_first_instance_in_file_of_user(char *filename, char *username);
int file_exists(char *filename);
char *join_strings(char *str1, char *str2);
int count_occurence(char *str, char delimiter);
int compare_scores_reverse(const void *a, const void *b);
int min(int a, int b);

#endif
