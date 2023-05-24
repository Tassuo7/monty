#include "monty.h"

/**
 * validate_push - validate "push" opcode
 * @arg: The arg
 * @line_number: The line number where the "push" operation occurs.
 * Return: void
 */
void validate_push(char *arg, unsigned int line_number)
{
	if (arg == NULL || (atoi(arg) == 0 && arg[0] != '0'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * validate_pall- Validate pall
 * @arg: The argument to validate.
 * @line_number: The line number where the "pall" operation occurs.
 * Return: void
 */
void validate_pall(char *arg, unsigned int line_number)
{
	if (arg != NULL)
	{
		fprintf(stderr, "L%d: usage: pall\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * validate_pint- Validate pint
 * @arg: The argument to validate.
 * @line_number: The line number where the "pint" operation occurs.
 * Return: void
 */
void validate_pint(char *arg, unsigned int line_number)
{
	if (arg != NULL)
	{
		fprintf(stderr, "L%d: usage: pint\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * validate_args - Validate the opcode.
 * @opcode: The opcode to validate.
 * @arg: The argument to validate.
 * @line_number: The line number where the operation occurs.
 * Return: void
 */
void validate_args(char *opcode, char *arg, unsigned int line_number)
{
	int i;
	operation_t operations[] = {
		{"push", validate_push},
		{"pall", validate_pall},
		{"pint", validate_pint},
		{"pop", NULL},
		{NULL, NULL}
	};

	for (i = 0; operations[i].opcode != NULL; ++i)
	{
		if (strcmp(opcode, operations[i].opcode) == 0)
		{
			operations[i].validate_func(arg, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
