#include <stdio.h>
#include <stddef.h>
#include "sort.h"
/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @n1: First node
 * @n2: Next node
 */
void swap_nodes(listint_t *n1, listint_t *n2)
{
	if (n1->prev != NULL)
		(n1->prev)->next = n2;
	if (n2->next != NULL)
		(n2->next)->prev = n1;
	n2->prev = n1->prev;
	n1->prev = n2;
	n1->next = n2->next;
	n2->next = n1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: A pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				if ((current->prev)->prev == NULL)
					*list = current->prev;
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < (current->prev)->n)
			{
				swap_nodes(current->prev, current);
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
