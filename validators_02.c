#include "monty.h"

/**
 * validate_pop - Validate pop
 * @arg: The argument to validate.
 * @line_number: The line number where the "pop" operation occurs.
 * Return: void
 */
int validate_pop(char *arg, unsigned int line_number)
{
	if (arg != NULL)
	{
		fprintf(stderr, "L%d: usage: pop\n", line_number);
		return (-1);
	}
	return (0);
}

/**
 * validate_add - Validate add
 * @arg: The argument to validate.
 * @line_number: The line number where the "pint" operation occurs.
 * Return: void
 */
int validate_add(char *arg, unsigned int line_number)
{
	(void)arg;
	(void)line_number;
	return (0);
}


/**
 * validate_nop - Validate nop
 * @arg: The argument to validate.
 * @line_number: The line number where the "pint" operation occurs.
 * Return: void
 */
int validate_nop(char *arg, unsigned int line_number)
{
	(void)arg;
	(void)line_number;
	return (0);
}
