#include "main.h"

/**
 * print_triangle - Prints a triangle, followed by a new line.
 * @size: The size of the triangle.
 *
 * Return: void.
 */
void print_triangle(int size)
{
	int row, hashes, spaces;

	if (size > 0)
	{
		for (row = 1; row <= size; row++)
		{
			for (spaces = size - row; spaces > 0; spaces--)
			{
				_putchar(' ');
			}
			for (hashes = 1; hashes <= row; hashes++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
