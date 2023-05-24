#include "monty.h"


/**
 * _rotl - rotates
 * @stack: ptr to the top of the stack.
 * @line_number: The line number where the push operation occurs.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_node, *tail;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	curr_node = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;

	tail->next = curr_node;
	curr_node->prev = tail;
	curr_node->next = NULL;
}
