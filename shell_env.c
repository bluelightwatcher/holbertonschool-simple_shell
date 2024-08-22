#include "main.h"

/**
 * shell_env - Prints the current environment
 */
void shell_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

