#include "monty.h"
#include "lists.h"


/**
 * div_hand - div instruction handling
 * @stack: pointer for stack to push to
 * @line_number: line number in file
 */
void div_hand(stack_t **stack, unsigned int line_number)
{
	int div = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_tnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_tnodeint_at_index(*stack, 1);

	if (tlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		tprintf(STDERR_FILENO, DIV_ZERO, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	div = node_1->n / node_0->n;
	delete_tnodeint_at_index(stack, 0);
	delete_tnodeint_at_index(stack, 0);
	node = add_tnodeint(stack, div);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}


/**
 * sub_hand - sub instruction handling
 * @stack: pointer for stack to push to
 * @line_number: line number in file
 */
void sub_hand(stack_t **stack, unsigned int line_number)
{
	int sub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_tnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_tnodeint_at_index(*stack, 1);

	if (tlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	delete_tnodeint_at_index(stack, 0);
	delete_tnodeint_at_index(stack, 0);
	node = add_tnodeint(stack, sub);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_hand - mod instruction handling
 * @stack: pointer for stack to push to
 * @line_number: line number in file
 */
void mod_hand(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_tnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_tnodeint_at_index(*stack, 1);

	if (tlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	delete_tnodeint_at_index(stack, 0);
	delete_tnodeint_at_index(stack, 0);
	node = add_tnodeint(stack, mod);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}


/**
 * mul_hand - mul instruction handling
 * @stack: pointer for stack to push to
 * @line_number: line number in file
 */
void mul_hand(stack_t **stack, unsigned int line_number)
{
	int mul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_fnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_fnodeint_at_index(*stack, 1);

	if (flistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	delete_fnodeint_at_index(stack, 0);
	delete_fnodeint_at_index(stack, 0);
	node = add_fnodeint(stack, mul);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
