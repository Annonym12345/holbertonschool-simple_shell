#include "shell.h"

/**
 * check_direct_path - Check if command is a direct path
 * @cmd: The command to check
 *
 * Return: cmd if it's a valid path, NULL otherwise
 */
char *check_direct_path(char *cmd)
{
	struct stat st;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (stat(cmd, &st) == 0)
			return (cmd);
	}
	return (NULL);
}

/**
 * build_full_path - Build full path from directory and command
 * @dir: Directory path
 * @cmd: Command name
 *
 * Return: Full path string, or NULL on failure
 */
char *build_full_path(char *dir, char *cmd)
{
	char *full_path;

	full_path = malloc(_strlen(dir) + _strlen(cmd) + 2);
	if (!full_path)
		return (NULL);

	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, cmd);

	return (full_path);
}

/**
 * search_in_path - Search for command in PATH directories
 * @cmd: The command to find
 * @path: PATH environment variable value
 *
 * Return: Full path if found, NULL otherwise
 */
char *search_in_path(char *cmd, char *path)
{
	char *path_copy, *token, *full_path;
	struct stat st;

	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		full_path = build_full_path(token, cmd);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * get_path - Get the full path of a command
 * @cmd: The command to find
 *
 * Return: The full path of the command, or NULL if not found
 */
char *get_path(char *cmd)
{
	char *path, *result;

	result = check_direct_path(cmd);
	if (result)
		return (result);

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	return (search_in_path(cmd, path));
}
