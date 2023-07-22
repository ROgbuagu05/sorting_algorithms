#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* get_value - gets value of a card
* @str: The value of card
*
* Return: relative value of card
*/
int get_value(const char *str)
{
	int i;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, array[i]) == 0)
		{
			return (i);
		}
	}
	exit(1);
}

/**
* swap_node - swaps a node
* @list: double pointer to list
* @node: The node to swap
*/
void swap_node(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
* sort_deck - sorts a linked list deck of cards
* @deck: double pointer to the deck
*/
void sort_deck(deck_node_t **deck)
{
	char swapped = 1, i1, i2;
	deck_node_t *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	current = *deck;
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			i1 = get_value(current->card->value) + 13 * current->card->kind;
			i2 = get_value(current->next->card->value) + 13 * current->next->card->kind;
			if (i1 > i2)
			{
				swap_node(deck, current);
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
			i1 = get_value(current->card->value) + 13 * current->card->kind;
			i2 = get_value(current->prev->card->value) + 13 * current->prev->card->kind;
			if (i1 < i2)
			{
				swap_node(deck, current->prev);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
