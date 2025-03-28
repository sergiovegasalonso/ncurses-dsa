#include "seryio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strings
char *get_concat_string(const char *str1, const char *str2)
{
    char *finalString = NULL;
    size_t n = 0;

    if (str1)
        n += strlen(str1);
    if (str2)
        n += strlen(str2);

    if ((str1 || str2) && (finalString = malloc(n + 1)) != NULL)
    {
        *finalString = '\0';

        if (str1)
            strcpy(finalString, str1);
        if (str2)
            strcat(finalString, str2);
    }

    return finalString;
}
