#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void print_error(Error error)
{
    fprintf(stderr, "Error %d: %s\n", error.code, error.message);
}

char *strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char *dup_str = malloc(len);
    if (!dup_str)
    {
        print_error((Error){1, "Memory allocation error"});
        return NULL;
    }
    return strcpy(dup_str, str);
}

