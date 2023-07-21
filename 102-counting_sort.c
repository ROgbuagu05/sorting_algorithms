#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to sort
 * @size: The size of array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, n;
	size_t i, j, array_size;

	if (array == NULL || size <= 1)
		return;
	array_size = array[0];
	for (i = 0; array[i]; i++)
	{
		if (array[i] > (int)array_size)
			array_size = array[i];
	}

	array_size += 1;

	counting_array = malloc(array_size * sizeof(int *));
	if (counting_array == NULL)
		return;

	for (i = 0; i < array_size; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]] += 1;

	for (i = 0; i <= array_size; i++)
		counting_array[i] += counting_array[i - 1];

	print_array(counting_array, array_size);

	for (i = 1, j = 0; i <= array_size; i++)
		if (counting_array[i] != counting_array[i - 1])
		{
			for (n = 0; n < counting_array[i] - counting_array[i - 1]; n++)
				array[j++] = i;
		}
	free(counting_array);
}
