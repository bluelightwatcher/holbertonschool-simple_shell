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

	input = process_input();
	if (input)
	{
		args = token_args(input);
		if (args)
		{
			execute_command(program_name, args, environ);
			free(args);
		}
		free(input);
	}
}
