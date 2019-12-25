#include "users_manager.h"

void set_users_file(char *file_path)
{
    users_file = join_strings("./data/", file_path);
}

void load_users()
{
    mkdir("./data", 0700);

    if (!file_exists(users_file))
    {
        append_to_file(users_file, "");
    }

    char *user_file_content, **users;
    load_file(users_file, &user_file_content);

    int size = split(user_file_content, "\n", &users);
    accounts = (account *)malloc(sizeof(account) * size);

    for (int i = 0; i < size; i++)
    {
        char **user;
        split(users[i], ":", &user);

        account user_data;

        strcpy(user_data.username, user[0]);
        strcpy(user_data.password, user[1]);

        accounts[i] = user_data;

        free(user);
    }

    accounts_length = size;

    free(user_file_content);
}

void *get_user_data(const char *username)
{
    for (int i = 0; i < accounts_length; i++)
    {
        if (!strcmp(accounts[i].username, username))
            return &accounts[i];
    }

    return NULL;
}

int check_if_user_exists(const char *username)
{
    account *user_data = (account *)get_user_data(username);

    if (user_data)
        return 1;

    return 0;
}

int authenticate_user(const char *username, const char *password)
{
    account *user_data = (account *)get_user_data(username);

    if (!strcmp(user_data->password, password))
        return 1;

    return 0;
}

void add_user(const char *username, const char *password)
{
    account user_data;

    strcpy(user_data.username, username);
    strcpy(user_data.password, password);

    accounts_length += 1;

    accounts = realloc(accounts, sizeof(account) * accounts_length);

    accounts[accounts_length - 1] = user_data;

    char data_to_save[250];

    sprintf(data_to_save, "%s:%s\n", user_data.username, user_data.password);
    append_to_file(users_file, data_to_save);
}
