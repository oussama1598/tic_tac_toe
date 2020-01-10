#include "ai_player.h"

// these functions is for the random ai
void get_empty_random_empty_cell(cell *empty_cell)
{
    cell empty_cells[9];

    int empty_cells_index = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix[i][j] == 0)
            {
                empty_cells_index += 1;

                cell empty_cell = {i, j};

                empty_cells[empty_cells_index] = empty_cell;
            }
        }
    }
    if (empty_cells_index > -1)
    {

        int random_cells_index = rand() % (empty_cells_index + 1);

        empty_cell->i = empty_cells[random_cells_index].i;
        empty_cell->j = empty_cells[random_cells_index].j;
    }
}

int play_next_move(int ai_type)
{
    if (ai_type == AGAINST_AI)
    {
        return 0;
    }

    if (ai_type == AGAINST_RADNOM)
    {
        cell empty_random_cell = {-1,
                                  -1};
        get_empty_random_empty_cell(&empty_random_cell);

        if (empty_random_cell.i == -1)
        {
            return NO_MOVES_LEFT;
        }

        game_matrix[empty_random_cell.i][empty_random_cell.j] = player_sign == 1 ? 2 : 1;
        game_history[empty_random_cell.i][empty_random_cell.j] = ++turns_played;

        return 0;
    }

    return 0;
}
