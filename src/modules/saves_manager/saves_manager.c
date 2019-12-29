#include "saves_manager.h"

void set_saves_file(char *file_path)
{
    saves_file = join_strings("./data/", file_path);
}

void load_saves()
{
    mkdir("./data", 0700);

    if (!file_exists(saves_file))
    {
        append_to_file(saves_file, "");
    }

    char *saves_file_content, **saves_data;
    int file_length = load_file(saves_file, &saves_file_content);

    if (file_length > 0)
    {

        int size = split(saves_file_content, "\n", &saves_data);

        saves = (save_data *)malloc(sizeof(save_data) * size);

        for (int i = 0; i < size; i++)
        {
            char **savedata;
            split(saves_data[i], ":", &savedata);

            if (strstr(savedata[2], logged_in_user) != NULL)
            {
                save_data save_content;

                strcpy(save_content.board_state, savedata[0]);
                strcpy(save_content.timestamp, savedata[1]);

                saves[i] = save_content;

                saves_length += 1;
            }

            free(savedata);
        }

        free(saves_file_content);
    }
}

int add_save(char *game_state, int force)
{
    if (saves_length < 3 && !force)
    {
        save_data savedata;
        char user[103];
        char timestamp[100];

        time_t tm = time(NULL);

        // add to the local list
        sprintf(savedata.timestamp, "%d", (int)tm);
        strcpy(savedata.board_state, game_state);

        saves_length += 1;
        saves = realloc(saves, sizeof(save_data) * saves_length);

        saves[saves_length - 1] = savedata;

        // add to the file
        sprintf(timestamp, ":%d", (int)tm);
        sprintf(user, ":%s:\n", logged_in_user);

        strcat(game_state, timestamp);
        strcat(game_state, user);

        append_to_file(saves_file, game_state);

        return 0;
    }
    else
    {
        return -1;
    }

    return 0;
}
