#include "monty.h"

/**
 * rotrl -  rotates the stack to the top
 * @stack: head of linkedlist
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: Nothing
 */
void rotrl(stack_t **stack, unsigned int line_number)
{

	stack_t *temp2 = NULL;
	stack_t *temp = NULL;
	(void)line_number;

	if (*stack == NULL || ((*stack)->next == NULL))
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp2 = temp->prev;
	temp2->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}

