#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * followed by a new line
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		pint_e(line_number);
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	printf("%d", temp->n);
	printf("\n");
}

