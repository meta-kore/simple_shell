#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "executor.h"
#include "utils.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
    printf("Shell Program\n");

    Command *cmd = parse_command("ls -l");
    if (cmd)
    {
        execute_command(cmd);
        free_command(cmd);
    }

    return EXIT_SUCCESS;
}

