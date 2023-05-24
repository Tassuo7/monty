#include "monty.h"


/**
 * _rotr - rotates
 * @stack: ptr to the top of the stack.
 * @line_number: The line number where the push operation occurs.
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_node;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	curr_node = *stack;

	while (curr_node->next != NULL)
		curr_node = curr_node->next;

	curr_node->next = *stack;
	curr_node->prev->next = NULL;
	curr_node->prev = NULL;
	(*stack)->prev = curr_node;
	*stack = curr_node;
}
