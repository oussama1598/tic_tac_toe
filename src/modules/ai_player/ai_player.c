#include "ai_player.h"

// these functions is for the random ai
int get_empty_random_empty_cell(int *j)
{
    int empty_cells[9][2];

    for (int i = 0; i < 9; i++)
    {
        empty_cells[i][0] = -1;
        empty_cells[i][1] = -1;
    }

    int empty_cells_index = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix[i][j] == 0)
            {
                empty_cells_index += 1;

                empty_cells[empty_cells_index][0] = i;
                empty_cells[empty_cells_index][1] = j;
            }
        }
    }

    if (empty_cells_index > -1)
    {

        int random_cells_index = rand() % (empty_cells_index + 1);

        *j = empty_cells[random_cells_index][1];

        return empty_cells[random_cells_index][0];
    }

    return -1;
}

int play_next_move(int ai_type)
{
    if (ai_type == AGAINST_AI)
    {
        return 0;
    }

    if (ai_type == AGAINST_RADNOM)
    {
        int random_empty_cell_j;
        int random_empty_cell_i = get_empty_random_empty_cell(&random_empty_cell_j);

        if (random_empty_cell_i == -1)
        {

            g_print("%s", "no moves left");

            return 0;
        }

        game_matrix[random_empty_cell_i][random_empty_cell_j] = player_sign == 1 ? 2 : 1;

        return 0;
    }

    return 0;
}
