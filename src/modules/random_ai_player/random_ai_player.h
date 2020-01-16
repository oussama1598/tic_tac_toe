#ifndef RANDOM_AI_PLAYER_H
#define RANDOM_AI_PLAYER_H

#include "imports.h"

/**
 * A structure that represents a single boards cell.
*/
typedef struct cell
{
    /**
     * The line's index for the current cell.
    */
    int i;
    /**
     * The column's index for the current cell.
    */
    int j;
} cell;

cell get_empty_random_empty_cell();
void random_ai_play_next_move();

#endif
