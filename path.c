#include "main.h"

/**
 * get_path_env_copy - Retrieves and duplicates the PATH environment variable.
 *
 * Return: A duplicated string of the PATH environment variable, or NULL if not found.
 */
char *get_path_env_copy(void)
{
    char *path_env = getenv("PATH");
    if (!path_env)
        return (NULL);

    return (strdup(path_env));
}


/**
 * find_executable_path - Finds the full path of a command.
 * @command: The command name.
 *
 * Return: The full path of the executable command, or NULL if not found.
 */
char *find_executable_path(char *command)
{
    char *path_env_copy, *directory, *full_path;
    struct stat st;

  
    if (command[0] == '/' || command[0] == '.')
    {
        if (access(command, X_OK) == 0)
            return (strdup(command));
        return (NULL);
    }
    path_env_copy = get_path_env_copy();
    if (!path_env_copy)
        return (NULL);

 
    directory = strtok(path_env_copy, ":");
    while (directory)
    {
        full_path = malloc(strlen(directory) + strlen(command) + 2);
        if (!full_path)
        {
            free(path_env_copy); 
            return (NULL);
        }

        sprintf(full_path, "%s/%s", directory, command);

        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
        {
            free(path_env_copy); 
            return (full_path);
        }

        free(full_path);
        directory = strtok(NULL, ":");
    }

    free(path_env_copy); 
    return (NULL);
}

