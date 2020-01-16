#include "random_ai_player.h"

/**
 * Gets a random empty cell from the board.
 * 
 * @return the random cell found or a cell of that contains -1 if no empty cells are found. 
*/
cell get_empty_random_empty_cell()
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

        return (cell){empty_cells[random_cells_index].i, empty_cells[random_cells_index].j};
    }

    return (cell){-1, -1};
}

/**
 * Plays a move from the random ai player.
*/
void random_ai_play_next_move()
{

    cell empty_random_cell = get_empty_random_empty_cell();

    if (empty_random_cell.i != -1)
    {
        game_matrix[empty_random_cell.i][empty_random_cell.j] = player_sign == 1 ? 2 : 1;
        game_history[empty_random_cell.i][empty_random_cell.j] = ++turns_played;
    }
}
