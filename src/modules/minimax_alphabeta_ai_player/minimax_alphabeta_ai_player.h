#ifndef MINIMAX_ALPHABETA_AI_PLAYER_H
#define MINIMAX_ALPHABETA_AI_PLAYER_H

#include "imports.h"
/**
 * A structure that will contain the minimax's data.
*/
typedef struct minimax_data
{
    /**
     * The weight of that certain move.
    */
    int weight;
    /**
     * The chosen cell's i index.
    */
    int i;
    /**
     * The chosen cell's j index.
    */
    int j;
} minimax_data;

/**
 * A copy of the game matrix to avoid any modification in the game's state.
*/
int game_matrix_copy[3][3];

int check_win_in_board();
minimax_data min_alpha_beta(int alpha, int beta);
minimax_data max_alpha_beta(int alpha, int beta);
void minimax_alphabeta_ai_play_next_move();

#endif
