#include "tools.h"

/**
 * Create a directory in both unix based systems and windows.
 *
 * @param dirname A constant string that represents the directory path.
 */
void create_dir(const char *dirname)
{
#if defined(_WIN32)
    _mkdir(dirname);
#else
    mkdir(dirname, 0700);
#endif
}

/**
 * Append to the end of a file.
 *
 * @param filename A string that represents the file path.
 * @param data A string that represents that data that should be appended to the end of file.
 */
void append_to_file(char *filename, char *data)
{
    FILE *file = fopen(filename, "a");

    fprintf(file, "%s", data);

    fclose(file);
}

/**
 * Updates the first line that belongs to a specific user with a provided data.
 *
 * @param filename A string that represents the file path.
 * @param data A string that represents that data that should we should replace with.
 * @param username the username for the specific user.
 */
void update_first_instance_in_file_of_user(char *filename, char *data, char *username)
{
    FILE *file = fopen(filename, "r");
    FILE *tmp = fopen("file.tmp", "w");

    char line[1000];

    while (fscanf(file, "%s\n", line) != -1)
    {
        char logged_username[120];
        sprintf(logged_username, ":%s:", logged_in_user);

        if (strstr(line, logged_username) != NULL) // this save belongs to the logged in user
        {
            fprintf(tmp, "%s", data);
        }
        else
            fprintf(tmp, "%s\n", line);
    }

    fclose(tmp);
    fclose(file);

    remove(filename);             // remove the old file
    rename("file.tmp", filename); // rename the temp to the new file
}

/**
 * Removes the first line that belongs to a specific.
 *
 * @param filename A string that represents the file path.
 * @param username the username for the specific user.
 */
void remove_first_instance_in_file_of_user(char *filename, char *username)
{
    FILE *file = fopen(filename, "r");
    FILE *tmp = fopen("file.tmp", "w");

    int already_deleted = 0;
    char line[1000];

    while (fscanf(file, "%s\n", line) != -1)
    {
        char logged_username[120];
        sprintf(logged_username, ":%s:", logged_in_user);

        if (strstr(line, logged_username) != NULL && !already_deleted)
        {
            already_deleted = 1;
        }
        else
            fprintf(tmp, "%s\n", line);
    }

    fclose(tmp);
    fclose(file);

    remove(filename);             // remove the old file
    rename("file.tmp", filename); // rename the temp to the new file
}

/**
 * Checks if the file exists on system or not.
 *
 * @param filename A string that represents the file path.
 * @return 1 if the file exists or 0 if not.
 */
int file_exists(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file != NULL)
    {
        fclose(file);
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Joins two strings together into one.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 * @return the combined string.
 */
char *join_strings(char *str1, char *str2)
{
    char *joined_str = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));

    strcpy(joined_str, str1);
    strcat(joined_str, str2);

    return joined_str;
}

/**
 * Compares two scores together
 *
 * @param a the first score which is an instance of the structure {@link score_data}
 * @param a the second score which is an instance of the structure {@link score_data}
 * @return the result of the substraction will give us which score is larger
 */
int compare_scores_reverse(const void *a, const void *b)
{
    return (((score_data *)b)->score - ((score_data *)a)->score);
}

/**
 * Returns the min of two number.
 *
 * @param a the first number.
 * @param b the second number.
 * @return the larger number.
 */
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
