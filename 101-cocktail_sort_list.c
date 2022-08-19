#include "sort.h"
#include <stdio.h>

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t *node)
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
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swap_node_ahead(list, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap_node_ahead(list, temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
