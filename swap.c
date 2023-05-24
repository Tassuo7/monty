#include "monty.h"

/**
 * _swap - function to swap the top two integers on the stack
 * @stack: input pointer to head of stack
 * @line_number: line count currently reading instructions from
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int swaper;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swaper = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swaper;
}

/**
 * validate_swap - Validate swap
 * @arg: The argument to validate.
 * @line_number: The line number where the "swap" operation occurs.
 * Return: void
 */
void validate_swap(char *arg, unsigned int line_number)
{
	if (arg != NULL)
	{
		fprintf(stderr, "L%d: usage: swap\n", line_number);
		exit(EXIT_FAILURE);
	}
}
