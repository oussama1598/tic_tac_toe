#include "tools.h"

int load_file(char *filename, char **file_content)
{
    int file_length = 0;

    FILE *file = fopen(filename, "r");

    // seek to the end of file so we can calculate its size
    fseek(file, 0, SEEK_END);

    // this function returns where the cursor is so the file size in this case
    file_length = ftell(file);

    // return back to the start for reading
    fseek(file, 0, SEEK_SET);

    if (file_length > 0)
    {

        *file_content = (char *)malloc(sizeof(char) * (file_length + 2));

        fread(*file_content, sizeof(char), file_length, file);

        fclose(file);

        (*file_content)[file_length + 1] = '\0';
    }

    return file_length;
}

void append_to_file(char *filename, char *data)
{
    FILE *file = fopen(filename, "a");

    fprintf(file, "%s", data);

    fclose(file);
}

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

char *join_strings(char *str1, char *str2)
{
    char *joined_str = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));

    strcpy(joined_str, str1);
    strcat(joined_str, str2);

    return joined_str;
}

int count_occurence(char *str, char delimiter)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == delimiter)
            count++;

    return count;
}

int compare_scores_reverse(const void *a, const void *b)
{
    return (((score_data *)b)->score - ((score_data *)a)->score);
}

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
