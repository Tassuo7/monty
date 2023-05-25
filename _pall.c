#include "monty.h"


/**
 * _pall - Pushes el on top of the stack.
 * @stack: ptr to the top of the stack.
 * @line_num: The line number where the push operation occurs.
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void)line_num;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
