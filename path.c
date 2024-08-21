#include "main.h"

/**
 * find_executable_path - Searches for the executable in the PATH directories
 * @command: Command to search for
 * @environ: The environment variables
 * Return: Full path to the executable or NULL if not found
 */

char *find_executable_path(char *command, char **environ)
{
	char *path_env, *path_dup, *token, *full_path;
	struct stat st;

	if (command == NULL || environ == NULL)
		return (NULL);

	if (strchr(command, '/'))
		return (command);

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_dup = strdup(path_env);
	if (path_dup == NULL)
		return (NULL);

	token = strtok(path_dup, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_dup);
			return (NULL);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_dup);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_dup);
	return (NULL);
}
