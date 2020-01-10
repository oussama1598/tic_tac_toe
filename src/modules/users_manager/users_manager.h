#ifndef USERS_MANAGER_H
#define USERS_MANAGER_H

#include "imports.h"
#include <sys/stat.h>
#include <sys/types.h>

typedef struct account
{
    char username[100];
    char password[100];
} account;

char *users_file;
account accounts[1000];
int accounts_length;
char logged_in_user[100];

void set_users_file(char *file_path);
void load_users();
void *get_user_data(const char *username);
int check_if_user_exists(const char *username);
int authenticate_user(const char *username, const char *password);
void add_user(const char *username, const char *password);

#endif
