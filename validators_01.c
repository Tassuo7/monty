#include "monty.h"

/**
 * validate_push - validate "push" opcode
 * @arg: The arg
 * @line_number: The line number where the "push" operation occurs.
 * Return: void
 */
int validate_push(char *arg, unsigned int line_number)
{
	if (arg == NULL || (atoi(arg) == 0 && arg[0] != '0'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (-1);
	}
	return (0);
}

/**
 * validate_pall- Validate pall
 * @arg: The argument to validate.
 * @line_number: The line number where the "pall" operation occurs.
 * Return: void
 */
int validate_pall(char *arg, unsigned int line_number)
{
	(void)arg;
	(void)line_number;
	return (0);
}

/**
 * validate_pint- Validate pint
 * @arg: The argument to validate.
 * @line_number: The line number where the "pint" operation occurs.
 * Return: void
 */
int validate_pint(char *arg, unsigned int line_number)
{
	(void)arg;
	(void)line_number;
	return (0);
}

/**
 * validate_swap - Validate swap
 * @arg: The argument to validate.
 * @line_number: The line number where the "swap" operation occurs.
 * Return: void
 */
int validate_swap(char *arg, unsigned int line_number)
{
	(void)arg;
	(void)line_number;
	return (0);
}


/**
 * validate_args - Validate the opcode.
 * @opcode: The opcode to validate.
 * @arg: The argument to validate.
 * @line_number: The line number where the operation occurs.
 * Return: void
 */
int validate_args(char *opcode, char *arg, unsigned int line_number)
{
	int i;
	operation_t operations[] = {
		{"push", validate_push},
		{"pall", validate_pall},
		{"pint", validate_pint},
		{"pop", validate_pop},
		{"swap", validate_swap},
		{"add", validate_add},
		{"nop", validate_nop},
		{NULL, NULL}
	};

	for (i = 0; operations[i].opcode != NULL; ++i)
	{
		if (strcmp(opcode, operations[i].opcode) == 0)
		{
			if (operations[i].validate_func(arg, line_number) == -1)
				return (-1);
			return (0);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	return (-1);
}
