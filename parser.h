#ifndef _PARSER_H_
#define _PARSER_H_

#include "utils.h"

typedef struct
{
    char *command;
} Command;

Command *parse_command(const char *input);
void free_command(Command *cmd);

#endif

