# simple_shell

A small UNIX command interpreter written in C, modelled on `sh`. It reads a line, resolves the command through `PATH`, forks, and runs it with `execve`, in interactive or piped (non-interactive) mode.

```
$ echo "ls" | ./hsh
```

## Build

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Compile every `.c` file in the repository root. The `first-run/` directory is the team's first draft of the shell, kept for history.

## Use

**Interactive:** run `./hsh`, type commands at the prompt, leave with `exit` or Ctrl-D.

**Non-interactive:** pipe commands in; the shell exits when they finish.

```sh
echo "/bin/ls -l" | ./hsh
```

## Built-ins

| Command | What it does |
|---|---|
| `exit [n]` | Leave the shell, with an optional exit status |
| `env` | Print the environment |
| `setenv VAR VALUE` | Set an environment variable |
| `unsetenv VAR` | Remove an environment variable |
| `cd [dir]` | Change directory |
| `echo` | Print arguments; expands `$$` (process id), `$?` (last exit status) and `$PATH` |

## Known limits

- `setenv` and `unsetenv` do not show up in `env` output or in the environment of child processes.
- There is no `help` built-in, pipes, redirection or job control.

## Layout

```
main.c               Read-eval loop
getline.c token.c    Input and tokenizing
handle_path.c        PATH lookup
exec.c               fork and execve
handle_*.c           Built-ins
change_dir.c         cd
string*.c print.c    String and output helpers
first-run/           Earlier draft of the shell
```

## Credits

Written by [Jones Mereu](https://github.com/meta-kore) and [Peter Pepple](https://github.com/Peterez-Git) as a milestone project for ALX Africa Software Engineering.
