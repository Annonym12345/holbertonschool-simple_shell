#include "shell.h"

/**
 * _strlen - Get the length of a string
 * @s: The string
 *
 * Return: The length of the string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if equal, negative if s1 < s2, positive if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcpy - Copy a string
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concatenate two strings
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;

	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL on failure
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t len = _strlen(str) + 1;

	dup = malloc(len);
	if (!dup)
		return (NULL);

	_strcpy(dup, str);
	return (dup);
}
