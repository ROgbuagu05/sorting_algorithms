#include <stdio.h>
#include "sort.h"
/**
 * bitonic_compare - compare and swap elements in the bitonic sequence
 * @up: 1 for ascending order, 0 for descending order
 * @array: array to sort
 * @size: array size
 */
void bitonic_compare(char up, int *array, size_t size)
{
	size_t i, j;
	int temp;

	j = size / 2;
	for (i = 0; i < j; i++)
	{
		if ((array[i] > array[i + j]) == up)
		{
			temp = array[i];
			array[i] = array[i + temp];
			array[i + temp] = temp;
		}
	}
}

/**
 * bitonic_merge - recursively merge bitonic sequences
 * @up: 1 for ascending order, 0 for descending order
 * @array: array
 * @size: array size
 */
void bitonic_merge(char up, int *array, size_t size)
{
	size_t mid = size / 2;

	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, mid);
	bitonic_merge(up, array + mid, mid);
}

/**
 * bitonic_sort_recursive - recursive bitonic sort algorithm
 * @up: direction of sorting (1 for ascending, 0 for descending)
 * @array: array to sort
 * @size: size of the array
 * @t: total size of the original array
 */
void bitonic_sort_recursive(char up, int *array, size_t size, size_t t)
{
	size_t mid = size / 2;

	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bitonic_sort_recursive(1, array, mid, t);
	bitonic_sort_recursive(0, array + mid, mid, t);
	bitonic_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: The array to be sort
 * @size: The size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sort_recursive(1, array, size, size);
}
