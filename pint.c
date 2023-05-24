#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: ptr to the stack to be pint
 * @line_num: the number of the line
 */

void pint(stack_t **stack, unsigned int line_num)
{

	if (!*stack)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
