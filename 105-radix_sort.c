#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * getMax - Gets the maximum value in array
 * @array: The array of integers
 * @size: The size of array
 * Return: The value of array
 */
int getMax(int *array, int size)
{
	int i, max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - Function to do counting sort of array
 * according to the digit represented by exp.
 * @array: The array of integers
 * @size: The size of array
 * @exp: The exp is 10^i
 * @output: array to save the temporary values
 */
void countingSort(int *array, size_t size, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: The array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp, maximum = 0;
	int *output = NULL;

	if (array == NULL || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
