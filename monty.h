#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - a doubly linkd list represnttion of stack (or queue)
 * @n: the integer
 * @prev: points previous element of the stack (or queue)
 * @next: the points to next element of the stack (or queue)
 *
 * Description: a dobly linkd list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - the opcode and its function
 * @opcode: opcode
 * @f: the function to handle the opcode
 *
 * Description: the opcode and function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - the structure of arguments from main
 * @av: name of file from command line
 * @ac: number of args from main
 * @line_number: number of current line in file
 *
 * Description: args passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_number;
} args_t;

/**
 * struct data_s - the extern data to access inside functions
 * @line: line from  file
 * @words: the parsed line
 * @stack: pointer to stack
 * @fptr: the file pointer
 * @qflag: the flag for queue or stack
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

void (*get_func(char **parsed))(stack_t **, unsigned int);
void push_hand(stack_t **stack, unsigned int line_number);
void pall_hand(stack_t **stack, unsigned int line_number);
void monty(args_t *args);
void pint_hand(stack_t **stack, unsigned int line_number);
void pop_hand(stack_t **stack, unsigned int line_number);
void swap_hand(stack_t **stack, unsigned int line_number);
void add_hand(stack_t **stack, unsigned int line_number);
void nop_hand(stack_t **stack, unsigned int line_number);
void rotl_hand(stack_t **stack, unsigned int line_number);
void rotr_hand(stack_t **stack, unsigned int line_number);
void stack_hand(stack_t **stack, unsigned int line_number);
void queue_hand(stack_t **stack, unsigned int line_number);
void sub_hand(stack_t **stack, unsigned int line_number);
void div_hand(stack_t **stack, unsigned int line_number);
void mul_hand(stack_t **stack, unsigned int line_number);
void mod_hand(stack_t **stack, unsigned int line_number);
void pchar_hand(stack_t **stack, unsigned int line_number);
void pstr_hand(stack_t **stack, unsigned int line_number);
int word_counter(char *s);
char **strtow(char *str);
void free_every(char **args);
void free_all(int all);

#endif
