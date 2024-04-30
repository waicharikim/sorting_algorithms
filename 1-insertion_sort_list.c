#include "sort.h"

/**
 * swapNodes - function swaps two doubly linked list nodes
 * @head: pointer to linked list
 * @node_1: pointer to the first node to swap
 * @node_2: node to swap
 *
 * Return: nothing
 */
void swapNodes(listint_t **head, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;

	if (node_2->next)
		node_2->next->prev = *node_1;

	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;

	if ((*node_1)->prev)
		(*node_1)->prev->next = node_2;
	else
		*head = node_2;

	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
}

/**
 * insertion_sort_list - function sorts a doubly linked list of integers
 * in ascending order(insertion sort algorithm)
 * @list: pointer to a doubly linked list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *e, *i;

	if (!list || !*list || !((*list)->next))
		return;
	for (e = (*list)->next; e; e = temp)
	{
		temp = e->next;
		i = e->prev;
		while (i && e->n < i->n)
		{
			swapNodes(list, &i, e);
			print_list((const listint_t *)*list);
		}
	}
}
