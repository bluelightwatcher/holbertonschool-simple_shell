#include "main.h"
/**
 * build_full_path - Constructs the full path to an executable.
 * @dir: The directory part of the path.
 * @command: The command to find.
 *
 * Return: The full path to the command if successful,
 * or NULL if allocation fails.
 */
char *build_full_path(char *dir, char *command)
{
	size_t dir_len = strlen(dir), command_len = strlen(command);
	char *full_path = malloc(dir_len + command_len + 2);

	if (!full_path)
		return (NULL);
	strcpy(full_path, dir);
	full_path[dir_len] = '/';
	strcpy(full_path + dir_len + 1, command);
	return (full_path);
}

/**
 * find_executable_path - Searches the PATH environment variable to find
 *                        the full path of a command.
 * @command: The command to find.
 *
 * Return: The full path to the executable command if found, or NULL otherwise.
 */

char *find_executable_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;

	/* If the command is an absolute or relative path */
	if (command[0] == '/' || command[0] == '.')
		return (access(command, X_OK) == 0 ? strdup(command) : NULL);

	/* Gets the PATH environment variable */
	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);
	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	/* Browse each directory in PATH */
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = build_full_path(dir, command);
		if (!full_path)
		{
			dir = strtok(NULL, ":");
			continue;
		}
		/* Checks if the command is executable */
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
