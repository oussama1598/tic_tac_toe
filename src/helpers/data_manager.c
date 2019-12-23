#include "data_manager.h"

void load_data()
{
    // create the data folder if it does not exist
    mkdir("./data", 0700);

    load_users();
}

void load_users()
{
    char *user_file_content, **users;
    load_file("./data/tes.txt", &user_file_content);

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
