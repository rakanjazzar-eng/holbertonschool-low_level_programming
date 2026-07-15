#include <stdio.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
void run_calculation(int choice, float num1, float num2);

/**
 * add - Adds two floating point numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The result of adding a and b.
 */
float add(float a, float b)
{
	return (a + b);
}

/**
 * subtract - Subtracts one floating point number from another.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The result of subtracting b from a.
 */
float subtract(float a, float b)
{
	return (a - b);
}

/**
 * multiply - Multiplies two floating point numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The result of multiplying a and b.
 */
float multiply(float a, float b)
{
	return (a * b);
}

/**
 * divide - Divides one floating point number by another.
 * @a: The dividend.
 * @b: The divisor.
 *
 * Return: The result of dividing a by b.
 */
float divide(float a, float b)
{
	return (a / b);
}

/**
 * run_calculation - Processes and prints the chosen math operation.
 * @choice: The user's menu choice.
 * @num1: The first operand.
 * @num2: The second operand.
 */
void run_calculation(int choice, float num1, float num2)
{
	if (choice == 1)
		printf("Result: %f\n", add(num1, num2));
	else if (choice == 2)
		printf("Result: %f\n", subtract(num1, num2));
	else if (choice == 3)
		printf("Result: %f\n", multiply(num1, num2));
	else if (choice == 4)
	{
		if (num2 == 0)
			printf("Error: division by zero\n");
		else
			printf("Result: %f\n", divide(num1, num2));
	}
}

/**
 * main - Entry point of the calculator program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	int choice;
	float num1, num2;

	printf("Simple Calculator\n");
	do {
		printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
		printf("Select an option: ");

		/* If scanf fails to read choice */
		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid choice\n");
			while (getchar() != '\n')
				; /* Clear stdin */
			choice = -1;
			continue;
		}

		if (choice >= 1 && choice <= 4)
		{
			printf("Enter the first number: ");
			if (scanf("%f", &num1) != 1)
			{
				printf("Invalid number\n");
				while (getchar() != '\n')
					;
				continue;
			}
			printf("Enter the second number: ");
			if (scanf("%f", &num2) != 1)
			{
				printf("Invalid number\n");
				while (getchar() != '\n')
					;
				continue;
			}
			run_calculation(choice, num1, num2);
		}
		else if (choice == 0)
		{
			printf("Bye!\n");
		}
		else
		{
			printf("Invalid choice\n");
		}
	} while (choice != 0);

	return (0);
}