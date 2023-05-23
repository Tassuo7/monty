#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: ptr to the stack to be pint
 * @line_num: the number of the line
 */

void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *pstack = *stack;

	if (!stack)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->prev != NULL)
	{
		(*stack) = (*stack)->prev;
	}
	(*stack)->prev = pstack;
	pstack->prev = NULL;
	pstack->next = *stack;
	exe_instr(NULL, "pall", pstack, line_num);
}
