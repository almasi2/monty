#include "monty.h"

/**
 * delete_tnodeint_at_index - wil delte node in a doubly linkd list
 * at a given index
 * @head: the double pointer to a list
 * @index: an index of a node to delete
 *
 * Return: 1 success, -1 failure
 */
int delete_tnodeint_at_index(tlistint_t **head, unsigned int index)
{
	tlistint_t *temp = *head;
	unsigned int i = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (i < index)
	{
		temp = temp->next;
		i++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
 * print_tlistint - Thsi prints a doubly linked list
 * @h: the pointer to a list
 *
 * Return: de numba of nodes in de list
 */
size_t print_tlistint(const tlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}

	return (nodes);
}
