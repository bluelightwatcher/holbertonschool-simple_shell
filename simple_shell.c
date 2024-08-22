#include "main.h"

/**
 * main - program recreates the basic shell
 * @argc: is the number or arguments passed to the program
 * @argv: is a string of command typed by the user
 * @environ: is a pointer to the program variable environment
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv, char **environ)
{
	char *input = NULL;
	int interactive = isatty(STDIN_FILENO);
	char **args = NULL;
	static char *program_name;

	(void)argc;
	program_name = argv[0];
	if (interactive)
	{
		while (1)
		{
			display_prompt();
			input = process_input();
			if (input == NULL)
			{
				printf("\n");
				break;
			}
			args = token_args(input);
			if (args == NULL)
			{
				free(input);
				continue;
			}
			execute_command(program_name, args, environ);
			free(input);
			free_args(args);
		}
	}
	else
	{
		non_interactive(program_name, environ);
	}
	return (0);
}
