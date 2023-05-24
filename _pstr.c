#include "monty.h"


/**
 * _pstr - prints string
 * @stack: ptr to the top of the stack.
 * @line_number: The line number where the push operation occurs.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_node = *stack;
	(void)line_number;

	while (curr_node != NULL)
	{
		if (curr_node->n > 0 && curr_node->n <= 127)
			printf("%c", curr_node->n);
		else
			break;
		curr_node = curr_node->next;
	}
	printf("\n");
}
