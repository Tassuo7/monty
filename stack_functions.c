#include "monty.h"


/**
 * _push - Pushes el on top of the stack.
 * @stack: ptr to the top of the stack.
 * @line_num: The line number where the push operation occurs.
 */
void _push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	(void)line_num;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = VALUE_TO_PUSH;
	new_node->prev = NULL;
	new_node->next =  *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

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
