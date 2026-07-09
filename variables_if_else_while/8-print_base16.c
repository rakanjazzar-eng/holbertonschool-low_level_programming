#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints all the numbers of base 16 in lowercase,
 * followed by a new line, using putchar three times.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char num;
	char ch;

	for (num = '0'; num <= '9'; num++)
	{
		putchar(num);
	}

	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}

	putchar('\n');

	return (0);
}
