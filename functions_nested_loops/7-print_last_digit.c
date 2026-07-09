#include "main.h"

/**
 * print_last_digit - Prints and returns the last digit of a number
 * @n: The number to extract the last digit from
 *
 * Description: Computes the modulo 10 of the number. If the result
 * is negative, converts it to positive before printing and returning.
 *
 * Return: The value of the last digit (0 through 9)
 */
int print_last_digit(int n)
{
	int last;

	last = n % 10;

	if (last < 0)
	{
		last = -last;
	}

	_putchar(last + '0');

	return (last);
}
