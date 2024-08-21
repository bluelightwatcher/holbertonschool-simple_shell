#include "main.h"

/**
 * token_args - tokenizes user input into args
 * @input: is the string storing the stdin
 * Return: pointer to args[]
 */
char **token_args(char *input)
{
	char **args = malloc(BUFFER_SIZE * sizeof(char *));
	char *token;
	int i = 0;

	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " ");
	while (token != NULL)
	{
		if (strlen(token) > 0)
		{
			args[i] = strdup(token);
			if (args[i] == NULL)
			{
				perror("strdup failed");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (i == 0)
	{
		free(args);
		return (NULL);
	}

	return (args);
}
