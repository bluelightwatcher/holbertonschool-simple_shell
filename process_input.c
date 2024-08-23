#include "main.h"

/**
 * process_input - stores the stdin in char *input
 * Return: char *input
 */
char *process_input(void)
{
	/*input set to NULL to let getline malloc space in memory */
	char *input = NULL;
	size_t input_size = 0;
	ssize_t line_length;

	line_length = getline(&input, &input_size, stdin);
	/*Checks if get line failled*/
	if (line_length == -1)
	{
		free(input);
		return (NULL);
	}
	 /* Change newline character to Null terminator */
	input[strcspn(input, "\n")] = '\0';
	return (input);
}

