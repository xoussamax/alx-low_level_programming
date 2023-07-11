#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL if str is NULL
 *         or if memory allocation fails.
 */
char *_strdup(char *str)
{
	if (str == NULL)
		return (NULL);

	unsigned int length = 0;

	while (str[length] != '\0')
		length++;

	char *duplicate = malloc((length + 1) * sizeof(char));

	if (duplicate != NULL)
	{
		unsigned int i;

		for (i = 0; i < length; i++)
			duplicate[i] = str[i];
		duplicate[length] = '\0';
	}

	return (duplicate);
}

