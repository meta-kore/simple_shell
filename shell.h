#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

typedef struct {
    char **argv;
    char **env;
    list_t *alias;
    list_t *history;
    int status;
    int line_count;
    int cmd_buf_type;
    char *path;
    int linecount_flag;
    int err_num;
} info_t;

// Function prototypes
void clear_info(info_t *info);
int interactive(info_t *info);
ssize_t get_input(info_t *info);
void set_info(info_t *info, char **av);
void free_info(info_t *info, int free_history);
void write_history(info_t *info);
void print_error(info_t *info, char *msg);
int is_chain(info_t *info, char *buf, size_t *p);
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
void fork_cmd(info_t *info);
void replace_string(char **old, char *new);
int replace_alias(info_t *info);
int replace_vars(info_t *info);

// Utility functions
int _putchar(char c);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);

// Parser functions
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);

#endif /* SHELL_H */

