#include "monty.h"
#include "lists.h"

/**
 * func_fetch - This selects the right function
 * @parsed: line frm  bytecode fil passed to main
 *
 * Return: This pointer points to the selcted function, or NULL on failure
 */
void (*func_fetch(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_hand},
		{"pall", pall_hand},
		{"pint", pint_hand},
		{"pop", pop_hand},
		{"swap", swap_hand},
		{"add", add_hand},
		{"nop", nop_hand},
		{"sub", sub_hand},
		{"div", div_hand},
		{"mul", mul_hand},
		{"mod", mod_hand},
		{"pchar", pchar_hand},
		{"pstr", pstr_hand},
		{"rotl", rotl_hand},
		{"rotr", rotr_hand},
		{"stack", stack_hand},
		{"queue", queue_hand},
		{NULL, NULL}
	};

	int codes = 17, j;

	for (j = 0; j < codes; j++)
	{
		if (strcmp(func_arr[j].opcode, parsed[0]) == 0)
		{
			return (func_arr[j].f);
		}
	}
	return (NULL);
}

/**
 * push_hand - This handles the push instrction
 * @stack: This doubles pointer to the stack to push to
 * @line_number: th number of a line in the file
 */
void push_hand(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, j;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (j = 0; data.words[1][j]; j++)
	{
		if (isalpha(data.words[1][j]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_hand - This will handles the pall instruction
 * @stack: a very double pointer to the stack to push to
 * @line_number: This is the number of the line in the file
 */
void pall_hand(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}
