#include "main.h"

/**
 * execute_command - forks a process to execute a command
 * @args: pointer to array of string args
 * @program_name: name of the program for error messages
 * @environ: pointer to array of environment variables
 * Return: void
 */
void execute_command(char *program_name, char **args, char **environ)
{
	pid_t pid;
	char *executable_path;

	executable_path = find_executable_path(args[0]);

	if (executable_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		return;
	}

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(executable_path, args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

	if (executable_path != args[0])
		free(executable_path);
}
