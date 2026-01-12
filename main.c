#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;

	(void)argc;
	(void)argv;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = split_line(line);

		if (args != NULL && args[0] != NULL)
			status = execute(args);

		free(line);
		free_array(args);

		line = NULL;
		args = NULL;
	}

	return (0);
}
