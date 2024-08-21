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

void non_interactive(char *program_name, char **environ);
char ** token_args(char *);
char * process_input(void);
void execute_command(char *program_name, char **args, char **env);
void display_prompt(void);


#endif
