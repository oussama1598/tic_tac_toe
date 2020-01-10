#ifndef MINIMAX_ALPHABETA_AI_PLAYER_H
#define MINIMAX_ALPHABETA_AI_PLAYER_H

#include "imports.h"

typedef struct minimax_data
{
    int weight;
    int i;
    int j;
} minimax_data;

int game_matrix_copy[3][3];

int check_win_in_board();
minimax_data min_alpha_beta(int alpha, int beta);
minimax_data max_alpha_beta(int alpha, int beta);
int minimax_alphabeta_ai_play_next_move();

#endif
