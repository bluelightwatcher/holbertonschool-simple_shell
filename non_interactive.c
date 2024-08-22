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

	line_length = getline(&input, &input_size, stdin);
	while (line_length != -1)
	{
		if (input[line_length - 1] == '\n')
			input[line_length - 1] = '\0';

		args = token_args(input);
		if (args && args[0])
			execute_command(program_name, args, environ);

		free_args(args);
		line_length = getline(&input, &input_size, stdin);
	}
	free(input);
}

