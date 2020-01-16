#include "saves_manager.h"

/**
 * Configures the path to the save file to be used later.
 * 
 * @param file_path the saves's file path.
*/
void set_saves_file(char *file_path)
{
    saves_file = join_strings("./data/", file_path);
}

/**
 * Loads all the saves from the file.
*/
void load_saves()
{
    create_dir("./data");

    if (!file_exists(saves_file))
    {
        append_to_file(saves_file, "");
    }

    saves_length = 0;

    FILE *saves_file_pointer = fopen(saves_file, "r");

    char save_line[300];

    while (fscanf(saves_file_pointer, "%s\n", save_line) != -1)
    {
        char logged_username[120];
        sprintf(logged_username, ":%s:", logged_in_user);

        if (strstr(save_line, logged_username) != NULL) // this save belongs to the logged in user
        {
            save_data save;

            strcpy(save.ai_type, strtok(save_line, ":"));
            strcpy(save.player_sign, strtok(NULL, ":"));
            strcpy(save.board_state, strtok(NULL, ":"));
            strcpy(save.timestamp, strtok(NULL, ":"));

            saves[saves_length] = save;

            saves_length += 1;
        }
    }

    fclose(saves_file_pointer);
}

/**
 * Adds a save for the current signed in user.
 * 
 * @param game_state the current boards values.
 * @param ai_type the ai type, 1 if you're playing against the minimax algorithm, 2 if you're playing against a random actions.
 * @param player_sign the current player's sign, 1 for O, 2 for X.
 * @param force either we should force the save or not, if we exceeded the max of 3 saves per user.
 * @return 0 if the save was successful, -1 if not. 
*/
int add_save(char *game_state, int ai_type, int player_sign, int force)
{
    if (saves_length < 3 || force)
    {
        save_data savedata;

        time_t tm = time(NULL);

        // add to the local list
        sprintf(savedata.timestamp, "%d", (int)tm);
        strcpy(savedata.board_state, game_state);

        sprintf(savedata.ai_type, "%d", ai_type);
        sprintf(savedata.player_sign, "%d", player_sign);

        if (!force)
        {
            saves_length += 1;

            saves[saves_length - 1] = savedata;
        }
        else
        {
            saves[0] = saves[1];
            saves[1] = saves[2];

            saves[2] = savedata;
        }

        // add to the file
        char to_save_data[300];

        sprintf(to_save_data, "%d:%d:%s:%d:%s:\n", ai_type, player_sign, game_state, (int)tm, logged_in_user);

        if (force)
            remove_first_instance_in_file_of_user(saves_file, logged_in_user);

        append_to_file(saves_file, to_save_data);

        return 0;
    }
    else
    {
        return -1;
    }

    return 0;
}
