#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string to be appended to.
 * @src: The source string to append.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int i = 0;

	while (dest[len] != '\0')
	{
		len++;
	}

	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}

	dest[len] = '\0';

	return (dest);
}
