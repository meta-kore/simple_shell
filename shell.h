#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define NOT_FOUND 127
#define PERMISSION_DENIED 126
#define EXIT_ERROR 2

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_PIPE 2
#define NON_INTERACTIVE_MODE 0
#define ERROR -1
#define TOK_D " \t\r\n\a\""


/**
 * struct list_paths - a struct made for nodes out of enviroment variable path
 * @path: enviroment variable path
 * @len: length of the path
 * @next: points to the next node
*/
typedef struct list_paths
{
	char *path;
	unsigned int len;
	struct list_paths *next;
} list_paths;

extern char **environ;
list_paths *paths_to_linkedlist();
size_t print_list(const list_paths *h);
void free_list(list_paths *head);
list_paths *add_node(list_paths **head, char *path);
unsigned int char_count(char *string, char character);
/*-----------*/

int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
/*----------*/
void print_env(int *status);
int check_mode(int argc);
char *check_access(char *line, list_paths *path_list);
char *scan_cmd_user(list_paths *current);
void free_array(char **argv);
void free_all(char *command, char **command_array);
void command_executer(char *path, char **av, char **env, int *status);
void scan_cmd_file(char *file);
char *check_input_file(char *file);
void free_list(list_paths *head);
char **line_to_vector(char *line, int status);
char *num_to_char(int num);
void print_error(char *shell_name, int count,
char *command_array, int type_of_error);
char *get_status(int n);
char *get_process_id();
char *_getenv(const char *name);
int builtin_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status,
list_paths *env_list, char **command_lines, char **argv);
void nonbuiltin_hndler(char **command_array, char *env[], int *status,
int count, list_paths *current, char *argv[]);
int custom_cd(char **command_array, char **argument_vector);
void custom_setenv(char *key, char *value, list_paths *current);
char **scan_command_files(int op_mode, char *file_name, char *shell_name);
char **noninteractive_files_handler(char *file_name, char *shell_name);
int dir_check(char *command, char **argument_vector, int count,
char **command_array, int *status, char *command_line_before);
char *number_to_character(int number);
char **text_to_array(char *text_read);
void cant_open_handler(char *program_name, int counter, char *file_name);
unsigned int piped_characters_count(char *string, char c);
char **noninteractive_pipes_handler();
char *get_non_interactive_command(char **command_lines, int count);
void permission_handler(char **command_array, int count,
char *executable, int *status, char *command);
void process_command(char *command, int *status, char ***command_array);
int line_count(char *line);
char **allocate_vector(int size);
void free_vector(char **vector);
char *process_token(char *token, int status);
int tokenize_command(char *command, int status, char **argument_vector);
char *flags_handler(char *token, char *command,
char **argument_vector, int status);
char *_strtok(char *str, const char *delimiters);
void free_whole(char **command_lines, int count, list_paths *env,
list_paths *current, char *command, char **command_array);
void exit_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status, list_paths *env,
char **command_lines);
void handle_comments(char *input);


#endif
