#include "shell.h"

/**
 * free_array - Free an array of strings
 * @array: The array to free
 */
void free_array(char **array)
{
	if (array)
		free(array);
}
