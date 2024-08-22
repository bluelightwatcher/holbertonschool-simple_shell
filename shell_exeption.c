#include "main.h"

/**
 * shell_exit - Exits the shell with a status code
 * @args: The command and its arguments
 *
 * Return: Does not return
 */

int shell_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
	}

	free_args(args);
	exit(status);
}
