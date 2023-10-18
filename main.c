#include "shell.h"

int main(int argc, char **argv, char **env)
{
    info_t info;
    ssize_t r = 0;
    int builtin_ret = 0;

    // Initialize info struct
    clear_info(&info);

    while (r != -1 && builtin_ret != -2)
    {
        clear_info(&info);
        if (interactive(&info))
            printf("$ ");
        fflush(stdout);

        r = get_input(&info);
        if (r != -1)
        {
            set_info(&info, argv);
            replace_alias(&info);
            replace_vars(&info);

            builtin_ret = find_builtin(&info);
            if (builtin_ret == -1)
                find_cmd(&info);
        }
        else if (interactive(&info))
            putchar('\n');

        free_info(&info, 0);
    }

    write_history(&info);
    free_info(&info, 1);

    if (!interactive(&info) && info.status)
        exit(info.status);

    if (builtin_ret == -2)
    {
        if (info.err_num == -1)
            exit(info.status);
        exit(info.err_num);
    }

    return (builtin_ret);
}

