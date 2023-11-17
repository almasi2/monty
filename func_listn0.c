#include "monty.h"

/**
 * add_tnodeint - This add new node at beginning of a doubly linked list
 * @head: The double pointer to the list
 * @n: data to be inserted in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
tlistint_t *add_tnodeint(tlistint_t **head, const int n)
{
	tlistint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(tlistint_t));
	if (!new)
		return (NULL);

	new->n = n;

	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * tlistint_len - This returns number of nodes in a doubly linked list
 * @h: the pointer to the list
 *
 * Return: the number of nodes
 */
size_t tlistint_len(const tlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}
