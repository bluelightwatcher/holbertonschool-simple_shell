#include "main.h"

/**
 * token_args - tokenizes user input into args
 * @input: is the string storing the stdin
 * Return: pointer to args[]
 */
char **token_args(char *input)
{
	char **args = NULL;
	char *token;
	size_t i = 0;
	size_t bufsize = BUFFER_SIZE;

	if (!input) /* Checks if input is valid */
		return (NULL);

	args = malloc(bufsize * sizeof(char *)); /* Allocates spaces for args */
	if (!args)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}
	/* Slicing string in multiple token/args */
	token = strtok(input, " \t\r\n\a"); 
	while (token != NULL)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			perror("Allocation error");
			free_args(args);
			exit(EXIT_FAILURE);
		}
		i++;
		/* Realloc memory if needed */
		if (i >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			args = realloc(args, bufsize * sizeof(char *));
			if (!args)
			{
				perror("Reallocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	args[i] = NULL; /* Last args has to be nulled*/
	return (args);
}

/**
 * free_args - frees memory allocated for args
 * @args: array of strings to free
 */
void free_args(char **args)
{
	size_t i = 0;

	if (!args)
		return;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
