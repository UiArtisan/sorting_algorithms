#include "sort.h"

void swap_node_forward(listint_t **, listint_t **, listint_t **);
void swap_node_backward(listint_t **, listint_t **, listint_t **);


/**
 * swap_node_forward - Swaps a node forward in a doubly-linked list.
 * @__head: Pointer to the head of the list.
 * @__tail: Pointer to the tail of the list.
 * @__shaker: Pointer to the node to be swapped.
 */
void swap_node_forward(listint_t **__head,
						listint_t **__tail, listint_t **__shaker)
{
	listint_t *node = (*__shaker)->next;

	if ((*__shaker)->prev != NULL)
		(*__shaker)->prev->next = node;
	else
		*__head = node;

	node->prev = (*__shaker)->prev;
	(*__shaker)->next = node->next;

	if (node->next != NULL)
		node->next->prev = *__shaker;
	else
		*__tail = *__shaker;

	(*__shaker)->prev = node;
	node->next = *__shaker;
	*__shaker = node;
}

/**
 * swap_node_backward - Swaps a node backward in a doubly-linked list.
 * @__head: Pointer to the head of the list.
 * @__tail: Pointer to the tail of the list.
 * @__shaker: Pointer to the node to be swapped.
 */
void swap_node_backward(listint_t **__head,
						listint_t **__tail, listint_t **__shaker)
{
	listint_t *node = (*__shaker)->prev;

	if ((*__shaker)->next != NULL)
		(*__shaker)->next->prev = node;
	else
		*__tail = node;
	node->next = (*__shaker)->next;
	(*__shaker)->prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = *__shaker;
	else
		*__head = *__shaker;
	(*__shaker)->next = node;
	node->prev = *__shaker;
	*__shaker = node;
}

/**
 * cocktail_sort_list - Sorts a doubly-linked list
 *		using the Cocktail Shaker Sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool is_sorted = false;

	if (!list || !*list || !(*list)->next)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (is_sorted == false)
	{
		is_sorted = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_forward(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				is_sorted = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_backward(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				is_sorted = false;
			}
		}
	}
}
