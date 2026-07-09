#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the alphabet in lowercase except for q and e,
 * followed by a new line, using putchar only twice.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
	{
		if (alpha != 'e' && alpha != 'q')
		{
			putchar(alpha);
		}
	}
	putchar('\n');

	return (0);
}
