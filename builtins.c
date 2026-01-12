#include "shell.h"

/**
 * builtin_exit - Exit the shell
 * @args: Array of arguments
 *
 * Return: 0 to signal exit
 */
int builtin_exit(char **args)
{
	(void)args;
	return (0);
}

/**
 * builtin_env - Print environment variables
 * @args: Array of arguments
 *
 * Return: Always 1 to continue execution
 */
int builtin_env(char **args)
{
	int i = 0;

	(void)args;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}

/**
 * builtin_cd - Change the current directory
 * @args: Array of arguments
 *
 * Return: Always 1 to continue execution
 */
int builtin_cd(char **args)
{
	char *home;

	if (args[1] == NULL)
	{
		home = _getenv("HOME");
		if (home == NULL)
		{
			perror("cd");
			return (1);
		}
		if (chdir(home) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
	return (1);
}
