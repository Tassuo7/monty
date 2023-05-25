#include "monty.h"

/**
 * stack_mode - stack or queue
 * @stack: ptr to the top of the stack.
 * @line_number: The line number where the push operation occurs.
 */

void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	MODE = STACK;
}


/**
 * queue_mode - queue mode
 * @stack: ptr to the top of the stack.
 * @line_number: The line number where the push operation occurs.
 */

void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	MODE = QUEUE;
}
