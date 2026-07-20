#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL on failure
 */

char *_strdup(char *str)
{
	if (str == NULL)
	{
		return (NULL);
	}

int i;
int size = 0;
char *dup;
for (i = 0; str[i] != '\0'; i++)
{
	size++;
}

	dup = malloc(sizeof(char) * (size + 1));

if (dup == NULL)
{
	return (NULL);
}
for (i = 0; i < size; i++)
{
	dup[i] = str[i];
}
dup[size] = '\0';

return (dup);
}
