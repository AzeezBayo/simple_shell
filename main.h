#ifndef MAIN_H
#define MAIN_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define BUFFER_SIZE 1024

extern char **environ;
char *_getline(void);

int shell_setenv(char **args);
int shell_unsetenv(char **args);
int handle_env_commands(char **args);

/**
 * struct data_shell - Structure representing shell data
 *
 * @_environ: Pointer to an array of strings
 * @status: Integer representing the status of the shell
 */
typedef struct data_shell
{
	char **_environ;
	int status;
} data_shell;
/*void execute_shell(void *datash, char **receive_argv);*/
int _env(data_shell *shell_data);
void handle_env(char *user_input, data_shell *shell_data);

char *_strtok(char *str, const char *delim);
char *_strdup(char *dup, char *str);
char *get_path(char *first_command);


char *prompt_read(ssize_t *fd_check);
int execute_command(char **receive_argv);
char **tokenization(char *take_user_input, char **argv, ssize_t fd_check);

char *accept_user_input(void);

int main(int ac, char **argv);
void (*get_command(char *cmd))(void);

/* strings related */
int s_len(char *string);
void s_copy(char *to, char *from);
void s_cat(char *text_add, char *text);

/* function related */
char **handle_path(void);
int check_ifCommand_exist(char *string);
char **split_string(char *string);

void print_error(char **av, char *err);
int _errputs(char *str);

char *_strchr(char *s, char c);
int _strcspn(char *s, char *charset);
int _strcmp(char *s, char *c);

void exit_shell(char **receive_argv, int execution_status);
int _atoi(char *s);

void free_array(char **argv);

int cd_command(char **args);
char *_getenv(const char *name);

#endif

