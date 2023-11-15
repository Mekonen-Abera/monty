#include "monty.h"

/**
 * pall - prints all the values on the stack
 * starting from the top of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;


	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_number != 1)
	{
		free_dlistint(*stack);
		free_globalvars();
		exit(EXIT_SUCCESS);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d", temp->n);
		temp = temp->prev;
		printf("\n");
	}
	printf("%d\n", temp->n);
}

