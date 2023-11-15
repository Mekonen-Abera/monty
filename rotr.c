#include "monty.h"

/**
 * rotr -  rotates the stack to the bottom
 * @stack: head of linkedlist
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp2 = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;
	temp2 = *stack;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = *stack;
	(*stack)->prev = temp2;
	temp2 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp2;
	(*stack)->prev = NULL;
}

