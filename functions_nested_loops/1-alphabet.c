#include "main.h"

/**
 * print_alphabet - Prints the alphabet in lowercase
 *
 * Description: Prints all letters of the alphabet from a to z,
 * followed by a new line, using _putchar only twice.
 *
 * Return: void
 */
void print_alphabet(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		_putchar(ch);
	}
	_putchar('\n');
}
