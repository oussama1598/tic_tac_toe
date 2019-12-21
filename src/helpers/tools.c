#include "tools.h"

char *join_strings(char *str1, char *str2)
{
    char *joined_str = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));

    strcpy(joined_str, str1);
    strcat(joined_str, str2);

    return joined_str;
}
