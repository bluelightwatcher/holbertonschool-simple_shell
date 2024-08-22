#include "main.h"

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

char *find_executable_path(char *command)
{
    char *path_env, *path_copy, *dir, *full_path;

    if (command[0] == '/' || command[0] == '.')
        return (access(command, X_OK) == 0 ? strdup(command) : NULL);
    path_env = getenv("PATH");
    if (!path_env || !(path_copy = strdup(path_env)))
        return (NULL);
    for (dir = strtok(path_copy, ":"); dir; dir = strtok(NULL, ":"))
    {
        if (!(full_path = build_full_path(dir, command)))
            continue;
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }
        free(full_path);
    }
    free(path_copy);
    return (NULL);
}

