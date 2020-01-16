#ifndef USERS_MANAGER_H
#define USERS_MANAGER_H

#include "imports.h"
#include <sys/stat.h>
#include <sys/types.h>

/**
 * A structure that will contain the user's data.
*/
typedef struct account
{
    /** A string that represents the user's username. */
    char username[100];
    /** A string that represents the user's password. */
    char password[100];
} account;

/**
 * The users's file path.
*/
char *users_file;
/**
 * The users list of type {@link account} it can hold up to 1000 scores.
*/
account accounts[1000];
/**
 * The accounts list length.
*/
int accounts_length;
/**
 * The username for the current signed in user.
*/
char logged_in_user[100];

void set_users_file(char *file_path);
void load_users();
account get_user_data(const char *username);
int check_if_user_exists(const char *username);
int authenticate_user(const char *username, const char *password);
void add_user(const char *username, const char *password);

#endif
