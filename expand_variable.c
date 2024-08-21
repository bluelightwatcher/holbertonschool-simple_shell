#include "main.h"

/**
 * expand_variables - Expands environment variables in the input string
 * @input: The input string with potential environment variables
 *
 * Return: A new string with the environment variables expanded
 */
char *expand_variables(char *input)
{
	char *expanded = malloc(BUFFER_SIZE);
	char *var;
	int i = 0, j = 0;

	while (input[i] != '\0')
	{
		if (input[i] == '$' && input[i + 1] != '\0')
		{
			var = getenv(&input[i + 1]);
			if (var != NULL)
			{
				strcpy(&expanded[j], var);
				j += strlen(var);
			}
			i += strlen(&input[i + 1]);
		}
		else
		{
			expanded[j++] = input[i++];
		}
	}
	expanded[j] = '\0';
	return (expanded);
}
