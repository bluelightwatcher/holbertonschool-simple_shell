#include "main.h"

/**
 * process_input - stores the stdin in char *input
 * Return: char *input
 */
char *process_input(void)
{
	char *input = NULL; /*input set to NULL to let getline malloc space in memory */
	size_t input_size = 0;
	ssize_t line_length;

	line_length = getline(&input, &input_size, stdin);
	if (line_length == -1) /*Checks if get line failled*/
	{
		free(input);
		return (NULL);  
	}

	input[strcspn(input, "\n")] = '\0'; /* Change newline character to Null terminator */
	return (input); 
}

