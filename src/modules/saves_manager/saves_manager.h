#ifndef SAVES_MANAGER_H
#define SAVES_MANAGER_H

#include "imports.h"

/**
 * A structure that will contain the save's data.
*/
typedef struct save_data
{
    /**
     * A string that will represents the ai's type.
    */
    char ai_type[5];
    /**
     * A string that represents the player's sign.
    */
    char player_sign[5];
    /**
     * A List that will contain the board's state.
    */
    char board_state[100];
    /**
     * Timestamp(current time and date) for the current save.
    */
    char timestamp[100];
} save_data;

/**
 * The save's file path.
*/
char *saves_file;
/**
 * The saves list of type {@link save_data} it can hold up to 3 saves for a certain user.
*/
save_data saves[3];

/**
 * The saves list length.
*/
int saves_length;

void set_saves_file(char *file_path);
void load_saves();
int add_save(char *game_state, int ai_type, int player_sign, int force);

#endif
