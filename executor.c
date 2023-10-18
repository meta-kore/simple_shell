#include <stdio.h>
#include "executor.h"
#include "utils.h"

void execute_command(const Command *cmd)
{
    if (!cmd)
    {
        print_error((Error){3, "Invalid command"});
        return;
    }

    printf("Executing command: %s\n", cmd->command);

    // TODO: Implement command execution, handle built-ins, etc.
}

