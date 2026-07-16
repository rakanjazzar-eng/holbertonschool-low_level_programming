#include "main.h"

/**
 * rev_string - Reverses a string in-place.
 * @s: The string to be reversed.
 *
 * Return: void.
 */
void rev_string(char *s)
{
	int len = 0;
	int start = 0;
	int end;
	char temp;

	while (s[len] != '\0')
	{
		len++;
	}

	end = len - 1;

	while (start < end)
	{
		temp = s[end];
		s[end] = s[start];
		s[start] = temp;

		start++;
		end--;
	}
}
