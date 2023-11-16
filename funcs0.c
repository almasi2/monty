#include "monty.h"
#include "lists.h"

/**
 * pint_hand - This will handles the pint instruction
 * @stack: The double pointer to the stack to push to
 * @line_number: A number of line in the file
 */
void pint_hand(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

/**
 * pop_hand - This  handles the pop instruction
 * @stack: This is a double pointer to the stack to push to
 * @line_number: a number of the line in the file
 */
void pop_hand(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}
