#include "monty.h"

/**
 * _mul - multiply the top two elements of the stack
 * @stack: the stack with the elements
 * @line_number: the command line number
 */

void _mul(stack_t **stack, unsigned int line_number)
{

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	(*stack)->n *= (*stack)->prev->n;
	(*stack)->prev = NULL;
}
