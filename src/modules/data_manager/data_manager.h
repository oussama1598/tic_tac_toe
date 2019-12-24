#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "imports.h"
#include <sys/stat.h>
#include <sys/types.h>

typedef struct account
{
    char username[100];
    char password[100];
} account;

account *accounts;

int accounts_length;

void load_data();
void load_users();

void *get_user_data(const char *username);
int check_if_user_exists(const char *username);
int authenticate_user(const char *username, const char *password);

#endif
