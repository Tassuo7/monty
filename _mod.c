#include "monty.h"

/**
 * _mod - computes the rest of the division of the 2nd by the top
 * @stack: stack with the div elements
 * @line_number: command line number
 */

void _mod(stack_t **stack, unsigned int line_number)
{

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	(*stack)->n %= (*stack)->prev->n;
	(*stack)->prev = NULL;
}
