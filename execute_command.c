#include "main.h"

/**
 * execute_command - Executes a command by forking a child process
 * @program_name: The name of the shell program
 * @args: The arguments for the command
 * @environ: The environment variables
 */
void execute_command(char *program_name, char **args, char **environ)
{
    char *executable_path;
    pid_t pid;
    int status;

    if (handle_builtin(args, environ))
    {
        return;
    }

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
        free(executable_path);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execve(executable_path, args, environ) == -1)
        {
            perror("execve failed");
            free(executable_path);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid failed");
        }
    }
    free(executable_path);
}
