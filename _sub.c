#include "monty.h"

/**
  * _sub - Subtracts the top element of the stack from the second one
  * @stack: the stack with the elements
  * @line_number: command Line number
  */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *elem = *stack;
	int subed;

	if (elem == NULL || elem->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	subed = (elem->next->n) - (elem->n);
	_pop(stack, line_number);
	(*stack)->n = subed;
}
