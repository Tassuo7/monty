#include "monty.h"

/**
 * _add - add top 2 elements.
 * @stack: ptr to the top of the stack.
 * @line_num: The line number where the push operation occurs.
 */
void _add(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_num);
	(*stack)->n = sum;

}
