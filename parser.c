#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "utils.h"

Command *parse_command(const char *input)
{
    Command *cmd = malloc(sizeof(Command));
    if (!cmd)
    {
        print_error((Error){1, "Memory allocation error"});
        return NULL;
    }

    char *command = strtok((char *)input, " ");
    if (!command)
    {
        print_error((Error){2, "Invalid command"});
        free(cmd);
        return NULL;
    }

    cmd->command = strdup(command);
    if (!cmd->command)
    {
        print_error((Error){1, "Memory allocation error"});
        free(cmd);
        return NULL;
    }

    return cmd;
}

void free_command(Command *cmd)
{
    if (!cmd)
        return;

    free(cmd->command);
    free(cmd);
}

