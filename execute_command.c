#include "main.h"

/**
 * execute_command - command forks a process to execute in child process
 * @args: is a pointer to array of string args
 * @program_name: name of the program required for the error message
 * @environ: is a pointer to array of environment variables
 * Return: void
 */

void execute_command(char *program_name, char **args, char **environ)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

}
