#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "add");
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*stack), op_e(line_number, "add");
	else
	{
		temp2->n = temp2->n + temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}

}
/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 */

void sub(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "sub");
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*stack), op_e(line_number, "sub");
	else
	{
		temp2->n = temp2->n - temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 */
void mul(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "mul");
		return;
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*stack), op_e(line_number, "mul");
	else
	{
		temp2->n = temp2->n * temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}

}
/**
 * div_m - divides the second top element of the stack
 * by the top element of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 */
void div_m(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "div");
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*stack), op_e(line_number, "div");
	else
	{
		if (temp->n == 0)
			div_e(line_number);
		temp2->n = temp2->n / temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}

}
/**
 * mod_m - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 */
void mod_m(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "mod");
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*stack), op_e(line_number, "mod");
	else
	{
		if (temp->n == 0)
			div_e(line_number);
		temp2->n = temp2->n % temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}

