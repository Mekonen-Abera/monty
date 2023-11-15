#include "monty.h"

/**
 * create_node_stackfirst - creates a node stack
 * @stack: A pointer to the top and bottom of the stack
 * @n: the value
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: The node
 */
stack_t *create_node_stackfirst(stack_t **stack, int n)
{
	stack_t *newnode_stack;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		stderr_malloc();
	newnode_stack->n = n;
	newnode_stack->next = *stack;
	newnode_stack->prev = NULL;
	*stack = newnode_stack;
	return (newnode_stack);
}

/**
 * create_node_stackend - creates a node stack at the end
 * @stack: A pointer to top and bottom stack
 * @n: the value
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: The node
 */
stack_t *create_node_stackend(stack_t **stack, int n)
{
	stack_t *newnode_stack;
	stack_t *temp;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		stderr_malloc();
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode_stack;
	newnode_stack->n = n;
	newnode_stack->prev = temp;
	newnode_stack->next = NULL;
	return (newnode_stack);
}
/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: pointer to the first element of the list
 * @n:integer
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: The pointer to a new node
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *newnode = NULL;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	if (*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return (newnode);
	}
	newnode->n = n;
	(*head)->prev = newnode;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}

