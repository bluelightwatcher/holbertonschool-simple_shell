#include "main.h"

/**
 * handle_builtin - Handles built-in commands
 * @args: The command and its arguments
 *
 * Return: 1 if the command is a built-in and executed, 0 otherwise
 */
int handle_builtin(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		return (shell_cd(args));
	}
	else if (strcmp(args[0], "export") == 0)
	{
		return (shell_export(args));
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		shell_exit(args);
	}
	return (0);
}
