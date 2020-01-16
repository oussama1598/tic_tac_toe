#include "users_manager.h"

/**
 * Configures the path to the users file to be used later.
 * 
 * @param file_path the users's file path.
*/
void set_users_file(char *file_path)
{
    users_file = join_strings("./data/", file_path);
}

/**
 * Loads all the users from the file.
*/
void load_users()
{
    create_dir("./data");

    if (!file_exists(users_file))
    {
        append_to_file(users_file, "");
    }

    accounts_length = 0;

    FILE *users_file_pointer = fopen(users_file, "r");

    char account_line[250];

    while (fscanf(users_file_pointer, "%s\n", account_line) != -1)
    {
        account account_data;

        strcpy(account_data.username, strtok(account_line, ":"));
        strcpy(account_data.password, strtok(NULL, ":"));

        accounts[accounts_length] = account_data;

        accounts_length += 1;
    }

    fclose(users_file_pointer);
}

/**
 * Get the user data for a specific user.
 * 
 * @param username A string that represents the user's username
 * @return the user data of type {@link account}.
*/
account get_user_data(const char *username)
{
    for (int i = 0; i < accounts_length; i++)
    {
        if (!strcmp(accounts[i].username, username))
            return accounts[i];
    }

    return (account){"", ""};
}

/**
 * Checks if user exists.
 * 
 * @param username A string that represents the user's username
 * @return 1 the user do exist, 0 if not.
*/
int check_if_user_exists(const char *username)
{
    account user_data = get_user_data(username);

    if (strcmp(user_data.username, "") != 0)
        return 1;

    return 0;
}

/**
 * Checks if the provided password is correct for a specific user.
 * 
 * @param username A string that represents the user's username
 * @param password A string that represents the user's password.
 * @return 1 if the provided password matchs the user's password, 0 if not.
*/
int authenticate_user(const char *username, const char *password)
{
    account user_data = get_user_data(username);

    if (!strcmp(user_data.password, password))
        return 1;

    return 0;
}

/**
 * Adds a new user to the users file and locally.
 * 
 * @param username A string that represents the user's username.
 * @param password A string that represents the user's password.
*/
void add_user(const char *username, const char *password)
{
    account user_data;

    strcpy(user_data.username, username);
    strcpy(user_data.password, password);

    accounts_length += 1;

    accounts[accounts_length - 1] = user_data;

    char data_to_save[250];

    sprintf(data_to_save, "%s:%s:\n", user_data.username, user_data.password);
    append_to_file(users_file, data_to_save);
}
