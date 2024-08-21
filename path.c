#include "main.h"
/**
 * get_path_env - Retrieves the PATH environment variable.
 *
 * Return: A copy of the PATH environment variable, or NULL if not found.
 */
char *get_path_env(void)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
		return (NULL);

	return (strdup(path_env));
}
/**
 * tokenize_path - Splits the PATH environment variable into directories.
 * @path_env: The PATH environment variable.
 *
 * Return: An array of directory strings, or NULL on failure.
 */
char **tokenize_path(char *path_env)
{
	char **tokens = malloc(BUFFER_SIZE * sizeof(char *));
	char *token;
	int i = 0;

	if (tokens == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}

	token = strtok(path_env, ":");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	tokens[i] = NULL;

	return (tokens);
}
/**
 * build_full_path - Constructs the full path of a command.
 * @directory: The directory in which the command is located.
 * @command: The command name.
 *
 * Return: The full path of the command, or NULL on failure.
 */
char *build_full_path(char *directory, char *command)
{
	char *full_path = malloc(strlen(directory) + strlen(command) + 2);

	if (full_path == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}

	strcpy(full_path, directory);
	strcat(full_path, "/");
	strcat(full_path, command);

	return (full_path);
}
/**
 * find_executable_in_directories - Searches directories for
 * an executable command.
 * @directories: An array of directory strings.
 * @command: The command name.
 *
 * Return: The full path of the executable command, or NULL if not found.
 *
 * Description: This function iterates over the provided directories,
 * attempting
 * to locate the specified command. If the command is found within any of the
 * directories, its full path is returned. If the command is not found in any
 * directory, NULL is returned.
 */
char *find_executable_in_directories(char **directories, char *command)
{
	struct stat st;
	char *full_path;
	int i = 0;

	while (directories[i] != NULL)
	{
		full_path = build_full_path(directories[i], command);
		if (full_path == NULL)
			continue;

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			return (full_path);
		}

		free(full_path);
		i++;
	}

	return (NULL);
}
/**
 * find_executable_path - Finds the full path of a command.
 * @command: The command name.
 *
 * Return: The full path of the executable command, or NULL if not found.
 */
char *find_executable_path(char *command)
{
	char *path_env, *path_env_dup, **directories, *full_path;
	int i;

	if (command[0] == '/' && access(command, X_OK) == 0)
		return (strdup(command));

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_env_dup = strdup(path_env);
	if (!path_env_dup)
		return (NULL);

	directories = tokenize_path(path_env_dup);
	free(path_env_dup);

	if (!directories)
		return (NULL);

	for (i = 0; directories[i]; i++)
	{
		full_path = build_full_path(directories[i], command);
		if (access(full_path, X_OK) == 0)
		{
			free(directories);
			return (full_path);
		}
		free(full_path);
	}

	free(directories);
	return (NULL);
}
