#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly-linked list.
 * @__h: Pointer to the head of the list.
 * @__fnode: Pointer to the first node to be swapped.
 * @__snode: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **__h, listint_t **__fnode, listint_t *__snode)
{
	(*__fnode)->next = __snode->next;
	if (__snode->next != NULL)
		__snode->next->prev = *__fnode;
	__snode->prev = (*__fnode)->prev;
	__snode->next = *__fnode;
	if ((*__fnode)->prev != NULL)
		(*__fnode)->prev->next = __snode;
	else
		*__h = __snode;
	(*__fnode)->prev = __snode;
	*__fnode = __snode->prev;
}

/**
 * insertion_sort_list - Sorts a doubly-linked list
 *			using the Insertion Sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *to_insert, *temp;

	if (!list || !*list || !(*list)->next)
		return;
	for (iter = (*list)->next; iter; iter = temp)
	{
		temp = iter->next;
		to_insert = iter->prev;
		while (to_insert && (iter->n < to_insert->n))
		{
			swap_nodes(list, &to_insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
