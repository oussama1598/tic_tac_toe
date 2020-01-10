#ifndef RANDOM_AI_PLAYER_H
#define RANDOM_AI_PLAYER_H

#include "imports.h"

typedef struct cell
{
    int i;
    int j;
} cell;

void get_empty_random_empty_cell(cell *empty_cell);
int random_ai_play_next_move();

#endif
