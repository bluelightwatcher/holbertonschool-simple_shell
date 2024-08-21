#include "main.h"

/**
 * display_prompt - displays prompt with no latency using fflush
 * Return: void
 */
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

