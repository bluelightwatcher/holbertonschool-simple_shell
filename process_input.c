#include "main.h"

/**
 * process_input - stores the stdin in char *input
 * Return: char *input
 */

char *process_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t line_length;

	line_length = getline(&input, &input_size, stdin);
	if (line_length == -1)
	{
		free(input);
		return (NULL); /* End of file (Ctrl-D) or error */
	}

	input[strcspn(input, "\n")] = '\0'; /* Remove newline character */
	return (input);
}
