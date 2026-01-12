#include "shell.h"

/**
 * read_line - Read a line from stdin
 *
 * Return: The line read from stdin, or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t read;

	read = getline(&line, &bufsize, stdin);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
