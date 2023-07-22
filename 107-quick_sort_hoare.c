#include <stdio.h>
#include "sort.h"
/**
 * swap - Swaps two elements in an array
 * @array: The array
 * @a: Pointer to array
 * @b: Pointer to array
 */
void swap(int *array, ssize_t a, ssize_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * partition - Partition sorting scheme implementation
 * @array: The array
 * @low: The array element
 * @high: The last array element
 * @size: The size of array
 * Return: Returns the position of the last element sorted
 */
int partition(int *array, int low, int high, int size)
{
	int i = low - 1, j = high + 1;
	int pivot = array[high];

	while (1)
	{

		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursive - Implementing quicksort algorithm
 * through recursion
 * @array: The array
 * @low: The array element
 * @high: The last array element
 * @size: The size of array
 */
void quick_sort_hoare_recursive(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t position = 0;

	if (low < high)
	{
		position = partition(array, low, high, size);
		quick_sort_hoare_recursive(array, low, position - 1, size);
		quick_sort_hoare_recursive(array, position, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array
 * @size: The size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_hoare_recursive(array, 0, size - 1, size);
}
