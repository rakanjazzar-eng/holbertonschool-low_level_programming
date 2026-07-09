#include "main.h"

/**
 * _isalpha - Checks for alphabetic character
 * @c: The character to check (represented as an integer)
 *
 * Description: Evaluates whether the passed ASCII value falls within
 * the lowercase ('a'-'z') or uppercase ('A'-'Z') alphabet ranges.
 *
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
