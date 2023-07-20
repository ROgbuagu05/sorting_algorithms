#include "sort.h"
/**
 * swap - swaps values on arrays
 * @a: A pointer to array
 * @b: A pointer to array
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation
 * @array: The array
 * @first: The first array element
 * @last: The last array element
 * @size: The size of array
 * Return: return the position of the last element
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				int temp = array[current];

				array[current] = array[finder];
				array[finder] = temp;
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		int temp = array[current];

		array[current] = array[last];
		array[last] = temp;
		print_array(array, size);
	}
	return (current);
}

/**
 * quicksort - quicksort algorithm implementation
 * @array: The array
 * @first: The first array element
 * @last: The last array element
 * @size: The size of array
 */
void quicksort(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		quicksort(array, first, position - 1, size);
		quicksort(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array
 * @size: The size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		quicksort(array, 0, size - 1, size);
}
