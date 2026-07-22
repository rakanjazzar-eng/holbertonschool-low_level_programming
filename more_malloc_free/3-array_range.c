#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: minimum value (included)
 * @max: maximum value (included)
 *
 * Return: pointer to newly created array, or NULL if it fails
 */
int *array_range(int min, int max)
{
	int i, range;
	int *array;

	if (min > max)
	{
		return (NULL);
	}

	range = max - min + 1;
	array = malloc(sizeof(int) * range);

	if (array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < range; i++)
	{
		array[i] = min + i;
	}

	return (array);
}
