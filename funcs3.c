#include "monty.h"
#include "lists.h"

/**
 * rotl_hand - This will handles  rotl instruction
 * @stack: The double pointer to the stack to push to
 * @line_number: a number of the line in the file
 */
void rotl_hand(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_tnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_tnodeint_at_index(stack, 0);
	add_tnodeint_end(stack, num);
}

/**
 * rotr_hand - This handles the rotr instruction
 * @stack: The double pointer to the stack to push to
 * @line_number: a specific number of the line in the file
 */
void rotr_hand(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0, len = tlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_tnodeint_at_index(*stack, len - 1);
	num = temp->n;
	delete_tnodeint_at_index(stack, len - 1);
	add_tnodeint(stack, num);
}
