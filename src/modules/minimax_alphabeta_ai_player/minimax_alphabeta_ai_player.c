#include "minimax_alphabeta_ai_player.h"

/**
 * Checks if any of the players did win
 * 
 * @return 1 if the user wins, 2 if the ai wins, 0 if none -1 if it's a tie.
*/
int check_win_in_board()
{
    // check lines
    for (int i = 0; i < 3; i++)
        if (game_matrix_copy[i][0] != 0 && game_matrix_copy[i][0] == game_matrix_copy[i][1] && game_matrix_copy[i][1] == game_matrix_copy[i][2])
            return game_matrix_copy[i][0] == player_sign ? PLAYER_WON : AI_WON;

    // check columns
    for (int j = 0; j < 3; j++)
        if (game_matrix_copy[0][j] != 0 && game_matrix_copy[0][j] == game_matrix_copy[1][j] && game_matrix_copy[1][j] == game_matrix_copy[2][j])
            return game_matrix_copy[0][j] == player_sign ? PLAYER_WON : AI_WON;

    if (game_matrix_copy[0][0] != 0 && game_matrix_copy[0][0] == game_matrix_copy[1][1] && game_matrix_copy[1][1] == game_matrix_copy[2][2])
        return game_matrix_copy[0][0] == player_sign ? PLAYER_WON : AI_WON;

    if (game_matrix_copy[0][2] != 0 && game_matrix_copy[0][2] == game_matrix_copy[1][1] && game_matrix_copy[1][1] == game_matrix_copy[2][0])
        return game_matrix_copy[0][2] == player_sign ? PLAYER_WON : AI_WON;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (game_matrix_copy[i][j] == 0)
                return 0;

    return NO_MOVES_LEFT;
}

/**
 * Applies the max function of the minimax algorithm
 * 
 * @return the selected cell which of type {@link minimax_data}.
 * @return the i index of the cell will be -1 if there's a win for each of the players or there is a tie.
*/
minimax_data max_alpha_beta(int alpha, int beta)
{
    int ai_sign = player_sign == X_SIGN ? O_SIGN : X_SIGN;

    int maxv = -2;
    int play_i = -1;
    int play_j = -1;

    int result = check_win_in_board();

    if (result == NO_MOVES_LEFT)
        return (minimax_data){0, -1, -1}; // tie
    else if (result == PLAYER_WON)
        return (minimax_data){-1, -1, -1}; // player wins
    else if (result == AI_WON)
        return (minimax_data){1, -1, -1}; // ai wins

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix_copy[i][j] == 0) // if cell is empty
            {
                game_matrix_copy[i][j] = ai_sign;

                minimax_data data = min_alpha_beta(alpha, beta);

                if (data.weight > maxv)
                {
                    maxv = data.weight;
                    play_i = i;
                    play_j = j;
                }

                game_matrix_copy[i][j] = 0;

                if (maxv >= beta)
                {
                    return (minimax_data){maxv, play_i, play_j};
                }

                if (maxv > alpha)
                    alpha = maxv;
            }
        }

    return (minimax_data){maxv, play_i, play_j};
}

/**
 * Applies the min function of the minimax algorithm
 * 
 * @return the selected cell which of type {@link minimax_data}.
 * @return the i index of the cell will be -1 if there's a win for each of the players or there is a tie.
*/
minimax_data min_alpha_beta(int alpha, int beta)
{
    int minv = 2;
    int play_i = -1;
    int play_j = -1;

    int result = check_win_in_board();

    if (result == NO_MOVES_LEFT)
        return (minimax_data){0, -1, -1}; // tie
    else if (result == PLAYER_WON)
        return (minimax_data){-1, -1, -1}; // player wins
    else if (result == AI_WON)
        return (minimax_data){1, -1, -1}; // ai wins

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix_copy[i][j] == 0) // if cell is empty
            {
                game_matrix_copy[i][j] = player_sign;

                minimax_data data = max_alpha_beta(alpha, beta);

                if (data.weight < minv)
                {
                    minv = data.weight;
                    play_i = i;
                    play_j = j;
                }

                game_matrix_copy[i][j] = 0;
                if (minv <= alpha)
                {
                    return (minimax_data){minv, play_i, play_j};
                }

                if (minv < beta)
                    beta = minv;
            }
        }

    return (minimax_data){minv, play_i, play_j};
}

/**
 * Plays a move with the minimax algorithm.
*/
void minimax_alphabeta_ai_play_next_move()
{
    // copy the game matrix
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            game_matrix_copy[i][j] = game_matrix[i][j];

    minimax_data data = max_alpha_beta(-2, 2);

    if (data.i != -1)
    {
        game_matrix[data.i][data.j] = player_sign == X_SIGN ? O_SIGN : X_SIGN;
        game_history[data.i][data.j] = ++turns_played;
    }
}
