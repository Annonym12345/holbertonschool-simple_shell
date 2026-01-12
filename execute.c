#include "shell.h"

/**
 * execute - Execute a command (builtin or external)
 * @args: Array of arguments (NULL terminated)
 *
 * Return: 1 to continue execution, 0 to exit
 */
int execute(char **args)
{
	int i;
	builtin_t builtins[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{"cd", builtin_cd},
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		{NULL, NULL}
	};

	if (args[0] == NULL)
		return (1);

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
			return (builtins[i].func(args));
	}

	return (launch(args));
}
