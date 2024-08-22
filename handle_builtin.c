#include "main.h"

/**
 * handle_builtin - Handles built-in commands
 * @args: The command and its arguments
 *
 * Return: 1 if the command is a built-in and executed, 0 otherwise
 */
int handle_builtin(char **args)
{
    if (strcmp(args[0], "exit") == 0)
    {
        shell_exit(args);
        return 1;
    }
    else if (strcmp(args[0], "env") == 0)
    {
        shell_env();
        return 1;
    }
    return 0;
}
