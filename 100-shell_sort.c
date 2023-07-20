#include <stdio.h>
#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: Array to sort
 * @size: The size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t knuth, i, j;
	int temp;

	knuth = 1;
	while (knuth < size)
		knuth = (knuth * 3) + 1;
	knuth = (knuth - 1) / 3;

	while (knuth > 0)
	{
		for (i = knuth; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= knuth && array[j - knuth] > temp; j -= knuth)
				array[j] = array[j - knuth];
			array[j] = temp;
		}
		knuth = (knuth - 1) / 3;
		print_array(array, size);
	}
}
