#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * create_stack_node - create a stack node
 * @stack: A pointer to top and bottom stack
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: 0 on success
 *       : -1 on failure
 */
int create_stack_node(stack_t **stack)
{
	stack_t *p;

	p = malloc(sizeof(stack_t));
	if (p == NULL)
	{
		fprintf(stderr, "Failed to allocate memory\n");
		return -1;
	}

	p->n = STACK;
	p->prev = NULL;
	p->next = NULL;

	*stack = p;

	return 0;
}

/**
 * free_stack - Frees a stack_t stack
 * @stack: A pointer to top and bottom stack
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *temp_node;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;
	}
}

/**
 * check_opcode - checks if STACK or QUEUE.
 * @stack: A pointer to top and bottom stack
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: The value of Stack or Queue.
 */
int check_opcode(stack_t *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Invalid stack pointer\n");
		return -1;
	}

	if (stack->n == STACK)
		return STACK;
	else if (stack->n == QUEUE)
		return QUEUE;
	else
	{
		fprintf(stderr, "Invalid stack type\n");
		return -1;
	}
}
