#ifndef _UTILS_H_
#define _UTILS_H_

typedef struct
{
    int code;
    const char *message;
} Error;

void print_error(Error error);
char *strdup(const char *str);

#endif

