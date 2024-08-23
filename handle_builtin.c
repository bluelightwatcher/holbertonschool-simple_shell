#include "main.h"

/**
 * handle_builtin - Handles built-in commands
 * @args: The command and its arguments
 *
 * Return: 1 if the command is a built-in and executed, 0 otherwise
 */
int handle_builtin(char **args)
{
	/* Vérifie si la commande est 'env' */
	if (strcmp(args[0], "env") == 0)
	{
		shell_env();
		return (1);
	}
	return (0);
}
