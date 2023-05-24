#include "monty.h"

/**
  * _pop - delete note at top of stack
  * @stack: pointer to head of stack
  * @line_number: line number
  */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *poped = (*stack);

	if (poped)
	{
		(*stack) = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	free(poped);
}


/**
 * validate_pop - Validate pop
 * @arg: The argument to validate.
 * @line_number: The line number where the "pop" operation occurs.
 * Return: void
 */
void validate_pop(char *arg, unsigned int line_number)
{
	if (arg != NULL)
	{
		fprintf(stderr, "L%d: usage: pop\n", line_number);
		exit(EXIT_FAILURE);
	}
}
