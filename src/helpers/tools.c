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

    *file_content = (char *)malloc(sizeof(char) * (file_length + 1));

    fread(*file_content, sizeof(char), file_length, file);

    fclose(file);

    (*file_content)[file_length + 1] = 0;

    return file_length;
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

int split(char *str, char *delimiter, char ***result)
{
    int size = count_occurence(str, *delimiter);

    *result = (char **)malloc(sizeof(char) * size);

    if (size > 0)
    {
        int index = 0;
        char *token = strtok(str, delimiter);

        while (token != NULL)
        {
            (*result)[index] = token;

            token = strtok(NULL, delimiter);
            index++;
        }

        return size;
    }

    return 0;
}
