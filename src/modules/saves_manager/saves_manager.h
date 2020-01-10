#ifndef SAVES_MANAGER_H
#define SAVES_MANAGER_H

#include "imports.h"

typedef struct save_data
{
    char ai_type[5];
    char board_state[100];
    char timestamp[100];
} save_data;

char *saves_file;
save_data saves[3];

int saves_length;

void set_saves_file(char *file_path);
void load_saves();
int add_save(char *game_state, int force);

#endif
