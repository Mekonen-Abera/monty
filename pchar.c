#include "monty.h"

/**
 * pchar -  prints the char at the top of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		pchar_e(line_number, "stack empty");
		return;
	}
	temp = (*stack);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->n < 0 || temp->n > 127)
	{
		pchar_e(line_number, "value out of range");
	}
	printf("%c\n", temp->n);
}

