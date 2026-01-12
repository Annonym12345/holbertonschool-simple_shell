#include "shell.h"

/**
 * builtin_setenv - Set an environment variable
 * @args: Array of arguments (setenv VARIABLE VALUE)
 *
 * Return: Always 1 to continue execution
 */
int builtin_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
		return (1);
	}

	if (_setenv(args[1], args[2], 1) != 0)
		perror("setenv");

	return (1);
}

/**
 * builtin_unsetenv - Unset an environment variable
 * @args: Array of arguments (unsetenv VARIABLE)
 *
 * Return: Always 1 to continue execution
 */
int builtin_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
		return (1);
	}

	if (_unsetenv(args[1]) != 0)
		perror("unsetenv");

	return (1);
}
