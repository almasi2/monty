#include "monty.h"
#include "lists.h"

/**
 * free_tlistint - frees a doubly linked list
 * @head: pointer to list to be freed
 */
void free_tlistint(tlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * get_tnodeint_at_index - gets the nth node
 * @head: list pointer
 * @index: index of node to return
 *
 * Return: address of node, or if it does not exist, NULL
 */
tlistint_t *get_tnodeint_at_index(tlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}
