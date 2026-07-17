#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
	char letters[] = "aAeEoOtTlL";
	char leet_chars[] = "4433007711";
	int i = 0;
	int j;

	while (str[i] != '\0')
	{
		j = 0;
		while (j < 10)
		{
			if (str[i] == letters[j])
			{
				str[i] = leet_chars[j];
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}
