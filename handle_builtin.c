#include "main.h"

/**
 * handle_builtin - Handles built-in commands
 * @args: The command and its arguments
 *
 * Return: 1 if the command is a built-in and executed, 0 otherwise
 */
int handle_builtin(char **args, char **environ)
{
    if (strcmp(args[0], "exit") == 0)
    {
        shell_exit(args);
    }
    else if (strcmp(args[0], "env") == 0)
    {
        print_env(environ);
        return (1);
    }
    return (0);
}

/**
 * print_env - Prints the current environment variables
 * @environ: The environment variables
 */
void print_env(char **environ)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

