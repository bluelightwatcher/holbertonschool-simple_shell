#include "main.h"

/**
 * handle_redirection - Handles file redirections
 * @args: The command and its arguments
 *
 * Return: 0 on success, -1 on failure
 */
int handle_redirection(char **args)
{
	int fd;
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], ">") == 0)
		{
			fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(fd, STDOUT_FILENO);
			close(fd);
			args[i] = NULL;
			break;
		}
		else if (strcmp(args[i], ">>") == 0)
		{
			fd = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			dup2(fd, STDOUT_FILENO);
			close(fd);
			args[i] = NULL;
			break;
		}
		else if (strcmp(args[i], "<") == 0)
		{
			fd = open(args[i + 1], O_RDONLY);
			if (fd == -1)
			{
				perror("hsh");
				return (-1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			args[i] = NULL;
			break;
		}
	}

	return (0);
}
