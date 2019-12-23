#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#define AGAINST_AI 1
#define AGAINST_RADNOM 2

#include "imports.h"

int get_empty_random_empty_cell(int *j);
int play_next_move(int ai_type);

#endif
