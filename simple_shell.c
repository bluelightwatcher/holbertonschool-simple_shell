#include "main.h"

/**
 * main - program recreates the basic shell
 * @argc: is the number of arguments passed to the program
 * @argv: is an array of command-line arguments
 * @environ: is a pointer to the program's environment variables
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv, char **environ)
{
    char *input = NULL;
    char **args = NULL;
    int interactive = isatty(STDIN_FILENO);

    (void)argc;

    if (interactive)
    {
        while (1)
        {
            display_prompt();
            input = process_input();
            if (!input)
            {
                if (feof(stdin))
                {
                    printf("\n");
                    break;
                }
                continue;
            }
            args = token_args(input);
            free(input);
            if (!args || !args[0])
            {
                free_args(args);
                continue;
            }
            execute_command(argv[0], args, environ);
            free_args(args);
        }
    }
    else
    {
        non_interactive(argv[0], environ);
    }
    return EXIT_SUCCESS;
}
