#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h> /* Required for open function */

/* Built-in command handlers */
int shell_exit(char **args);

/* Command execution */
void execute_command(char *program_name, char **args, char **environ);

/* Utility functions */
int handle_builtin(char **args);
int handle_redirection(char **args);
char *expand_variables(char *input);

/* Path-related functions */
char *get_path_env(void);
char **tokenize_path(char *path_env);
char *build_full_path(char *directory, char *command);
char *find_executable_in_directories(char **directories, char *command);
char *find_executable_path(char *command);

/* Shell operation functions */
void non_interactive(char *program_name, char **environ);
char **token_args(char *input);
char *process_input(void);
void display_prompt(void);

void free_args(char **args);

#endif /* MAIN_H */
