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

extern char **environ;

/* Built-in command handlers */
void shell_env(void);

/* Command execution */
void execute_command(char *program_name, char **args, char **environ);

/* Utility functions */
int handle_builtin(char **args);
char *expand_variables(char *input);

/* Path-related functions */
char *find_executable_path(char *command);

/* Shell operation functions */
void non_interactive(char *program_name, char **environ);
char **token_args(char *input);
char *process_input(void);
void display_prompt(void);
void free_args(char **args);

#endif /* MAIN_H */
