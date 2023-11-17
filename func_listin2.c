#include "monty.h"
#include "lists.h"

/**
 * insert_tnodeint_at_index - introduces a node at a given index
 * @h: list pointer
 * @idx: node index to insert
 * @n: data to insert
 *
 * Return: address of new node, NULL if it fails
 */
tlistint_t *insert_tnodeint_at_index(tlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	tlistint_t *new;
	tlistint_t *temp = *h;

	if (idx == 0)
		return (add_tnodeint(h, n));

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (add_tnodeint_end(h, n));
			new = malloc(sizeof(tlistint_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * add_tnodeint_end - inserts new node at doubly linked list end
 * @head: list pointer
 * @n: data to insert
 *
 * Return: the address of new element, NULL if it fails
 */
tlistint_t *add_tnodeint_end(tlistint_t **head, const int n)
{
	tlistint_t *new;
	tlistint_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(tlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}
