#include "main.h"

/**
 * shell_cd - Changes the current directory
 * @args: The command and its arguments
 *
 * Return: 1 on success or failure
 */
int shell_cd(char **args)
{
	char *home = getenv("HOME");

	if (args[1] == NULL)
	{
		if (home == NULL)
		{
			fprintf(stderr, "hsh: cd: HOME not set\n");
			return (1);
		}
		if (chdir(home) != 0)
		{
			perror("hsh");
			return (1);
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
			return (1);
		}
	}
	return (1);
}

/**
 * shell_export - Sets an environment variable
 * @args: The command and its arguments
 *
 * Return: 1 on success or failure
 */
int shell_export(char **args)
{
	char *name, *value;

	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: export: not enough arguments\n");
		return (1);
	}

	name = strtok(args[1], "=");
	value = strtok(NULL, "=");

	if (value == NULL)
	{
		fprintf(stderr, "hsh: export: invalid format\n");
		return (1);
	}

	if (setenv(name, value, 1) != 0)
	{
		perror("hsh");
		return (1);
	}

	return (1);
}

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

	exit(status);
}
