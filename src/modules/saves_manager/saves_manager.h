#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "imports.h"

char *saves_file;
char *saves;

int saves_length;

void set_saves_file(char *file_path);
void load_saves();
int add_save(char *game_state, int force);

#endif
