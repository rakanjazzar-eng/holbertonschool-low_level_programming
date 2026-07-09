#include "main.h"

/**
 * _abs - Computes the absolute value of an integer
 * @n: The integer to check
 *
 * Description: Converts negative integers to positive, while leaving
 * zero and positive integers unchanged.
 *
 * Return: The absolute value of the integer
 */
int _abs(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	else
	{
		return (n);
	}
}
