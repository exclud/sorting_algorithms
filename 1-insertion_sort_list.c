#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion Sort.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = (*list)->next;

	while (sorted != NULL)
	{
		current = sorted;
		sorted = sorted->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* Swap the nodes */
			temp = current->prev;
			current->prev = temp->prev;
			temp->prev = current;
			temp->next = current->next;
			current->next = temp;

			if (temp->next != NULL)
				temp->next->prev = temp;

			if (current->prev != NULL)
				current->prev->next = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}
	}
}
