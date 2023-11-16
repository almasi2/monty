#include "monty.h"
#include "lists.h"

/**
 * stack_hand - This will handle the stack instruction
 * @stack: This is a double pointer to the stack to push to
 * @line_number: The number of the line in the file
 */
void stack_hand(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}


/**
 * queue_hand - This will handle the queue instruction
 * @stack: This is a double pointer to the stack to push to
 * @line_number: The number of the line in the file
 */
void queue_hand(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}
