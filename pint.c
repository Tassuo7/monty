#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: ptr to the stack to be pint
 * @line_num: the number of the line
 */

void _pint(stack_t **stack, unsigned int line_num)
{
	stack_t *pstack = *stack;

	if (pstack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", pstack->n);
}
