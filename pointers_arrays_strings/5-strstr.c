#include "main.h"

/**
 * _strstr - Locates a substring.
 * @haystack: The main string to be searched.
 * @needle: The substring to locate.
 *
 * Return: A pointer to the beginning of the located substring,
 * or 0 (NULL) if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j;

	if (*needle == '\0')
	{
		return (haystack);
	}

	while (haystack[i] != '\0')
	{
		j = 0;

		while (haystack[i + j] == needle[j] && needle[j] != '\0')
		{
			j++;
		}

		if (needle[j] == '\0')
		{
			return (&haystack[i]);
		}

		i++;
	}

	return (0);
}
