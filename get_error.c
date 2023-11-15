#include "monty.h"

/**
 * pop_e - pop error message for the empty stack
 * @line_number: line number of the commands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: EXIT_FAILURE
 */
void pop_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * pint_e - pint error message for the empty stacks
 * @line_number: line number of thecommands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: EXIT_FAILURE
 */
void pint_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * op_e - math function the error messagess
 * @line_number: line number of the command
 * @op: Operation where error occurred
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: EXIT_FAILURE
 */
void op_e(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	free_globalvars();
	exit(EXIT_FAILURE);
}
/**
 * pchar_e - pchar error msg for 0 stack & and non-char val
 * @line_number: line number of the commands
 * @msg: error message to be printed
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: EXIT_FAILURE
 */
void pchar_e(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * div_e - The error for div by 0 occured
 * @line_number: line number of thecommands
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 * Return: EXIT_FAILURE
 */
void div_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

