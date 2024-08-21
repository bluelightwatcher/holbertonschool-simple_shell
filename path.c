#include "main.h"

char *get_path_env(void)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
		return (NULL);

	return (strdup(path_env));
}



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
			return (full_path);

		free(full_path);
		i++;
	}

	return (NULL);
}


char *find_executable_path(char *command)
{
	char *path_env, *full_path;
	char **directories;

	if (command == NULL || strchr(command, '/'))
		return (command);

	path_env = get_path_env();
	if (path_env == NULL)
		return (NULL);

	directories = tokenize_path(path_env);
	free(path_env);

	if (directories == NULL)
		return (NULL);

	full_path = find_executable_in_directories(directories, command);
	free(directories);

	return (full_path);
}
