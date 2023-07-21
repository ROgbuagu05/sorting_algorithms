#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * siftDown - fixes heap
 * @array: Array to be sorted
 * @size: The size of array
 * @index: Index of the heap
 * @h: Size of heap
 */
void siftDown(int *array, int size, int index, int h)
{
	int max = index, left = index * 2 + 1, right = index * 2 + 2;
	int tmp;

	if (left < h && array[left] > array[max])
		max = left;

	if (right < h && array[right] > array[max])
		max = right;

	if (max != index)
	{
		tmp = array[index];
		array[index] = array[max];
		array[max] = tmp;
		print_array(array, size);
		siftDown(array, size, max, h);
	}
}
/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to sort
 * @size: The size of array
 */
void heap_sort(int *array, size_t size)
{
	unsigned int i, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i > 0; i--)
		siftDown(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		if (i != 0)
			print_array(array, size);
		siftDown(array, size, 0, i);
	}
}
