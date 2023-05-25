#include "monty.h"

/**
 * push_s - Pushes el to stack
 * @stack: ptr to the top of the stack.
 * @new_node: the node to push
 */
void push_s(stack_t **stack, stack_t *new_node)
{
	new_node->prev = NULL;
	new_node->next =  *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * push_q - Pushes el to queue.
 * @stack: ptr to the top of the stack.
 * @new_node: the node to push
 */
void push_q(stack_t **stack, stack_t *new_node)
{
	stack_t *tail = *stack;

	if (tail == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{

		while (tail->next)
			tail = tail->next;
		tail->next = new_node;
		new_node->prev = tail;
	}
	new_node->next = NULL;
}

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
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = VALUE_TO_PUSH;

	if (MODE == STACK)
		push_s(stack, new_node);
	else
		push_q(stack, new_node);
}
