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

    // char *saves_file_content, **saves;
    // load_file(saves_file, &saves_file_content);

    // int size = split(saves_file_content, "\n", &saves);

    // add to the list only if it belongs to the user
    //accounts = (account *)malloc(sizeof(account) * size);

    // for (int i = 0; i < size; i++)
    // {
    //     char **user;
    //     split(saves[i], ":", &user);

    //     account user_data;

    //     strcpy(user_data.username, user[0]);
    //     strcpy(user_data.password, user[1]);

    //     accounts[i] = user_data;

    //     free(user);
    // }

    saves_length = 0;

    // free(user_file_content);
}

int add_save(char *game_state, int force)
{
    if (saves_length < 3 && !force)
    {
        char user[103];
        sprintf(user, ":%s\n", logged_in_user);

        strcat(game_state, user);

        append_to_file(saves_file, game_state);

        return 0;
    }else{
        return -1;
    }

    return 0;
}
