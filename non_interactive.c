#include "main.h"

/**
 * non_interactive - handles non-interactive mode of the shell
 * @program_name: is the name of the program
 * @environ: is a pointer to the program's environment variables
 */
void non_interactive(char *program_name, char **environ)
{
	char *input = NULL;
	char **args = NULL;
	size_t input_size = 0;
	ssize_t line_length;

	while ((line_length = getline(&input, &input_size, stdin)) != -1)
	{
		/* Remove the newline character from the input */
		input[strcspn(input, "\n")] = '\0';

		/* Tokenize the input and execute the command */
		args = token_args(input);
		if (args)
		{
			execute_command(program_name, args, environ);
			free_args(args);
		}
	}

	free(input);
}
