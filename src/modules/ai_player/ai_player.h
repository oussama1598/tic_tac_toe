#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#define AGAINST_AI 1
#define AGAINST_RADNOM 2

#include "imports.h"

typedef struct cell
{
    int i;
    int j;
} cell;

void get_empty_random_empty_cell(cell *empty_cell);
int play_next_move(int ai_type);

#endif
