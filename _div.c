#include "monty.h"

/**
 * _div - divide the 2nd by the top element
 * @stack: the stackwith the elements
 * @line_number: command line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*divide second top el with the top el*/
	(*stack)->next->n /= (*stack)->n;

	/*pop the old top*/
	_pop(stack, line_number);
}
