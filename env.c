#include "shell.h"

/**
 * compare_env_name - Compare environment variable name
 * @env_str: Environment string (NAME=value)
 * @name: Name to compare
 * @len: Length of name
 *
 * Return: 1 if match, 0 otherwise
 */
int compare_env_name(char *env_str, const char *name, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++)
	{
		if (env_str[i] != name[i])
			return (0);
	}
	if (env_str[len] == '=')
		return (1);
	return (0);
}

/**
 * _getenv - Get an environment variable value
 * @name: The name of the variable
 *
 * Return: The value of the variable, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len;

	if (!name)
		return (NULL);

	len = _strlen(name);

	while (environ[i])
	{
		if (compare_env_name(environ[i], name, len))
			return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}

/**
 * _setenv - Set an environment variable
 * @name: The name of the variable
 * @value: The value to set
 * @overwrite: Whether to overwrite existing variable
 *
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_var;
	int i = 0, len;
	size_t name_len;

	if (!name || !value || name[0] == '\0')
		return (-1);

	name_len = _strlen(name);
	len = name_len + _strlen(value) + 2;
	new_var = malloc(len);
	if (!new_var)
		return (-1);

	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var, value);

	while (environ[i])
	{
		if (compare_env_name(environ[i], name, name_len))
		{
			if (overwrite)
				environ[i] = new_var;
			else
				free(new_var);
			return (0);
		}
		i++;
	}
	return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @name: The name of the variable
 *
 * Return: 0 on success, -1 on error
 */
int _unsetenv(const char *name)
{
	int i = 0, j;
	size_t name_len;

	if (!name || name[0] == '\0')
		return (-1);

	name_len = _strlen(name);

	while (environ[i])
	{
		if (compare_env_name(environ[i], name, name_len))
		{
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
			return (0);
		}
		i++;
	}

	return (0);
}
