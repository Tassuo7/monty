#include "monty.h"

/**
 * parse_line - Parse a line of code.
 * @curr_line: The line of code to parse.
 * @stack: A pointer to the stack.
 * @line_num: The line number of the code.
 * Return: void
 */
void parse_line(char *curr_line, stack_t **stack, unsigned int line_num)
{
	char *opcode = strtok(curr_line, " \t\n"), *arg;

	if (opcode == NULL || opcode[0] == '#')
		return;

	arg = strtok(NULL, " \t\n");
	validate_args(opcode, arg, line_num);
	exe_instr(opcode, arg, stack, line_num);
}

/**
 * parse_file - Parse a file line by line
 * @file_ptr: A pointer to the file.
 * @stack: A pointer to the stack.
 * Return: void
 */
void parse_file(FILE *file_ptr, stack_t **stack)
{
	char *curr_line = NULL;
	size_t len = 0;
	unsigned int line_num = 0;
	ssize_t read;

	while ((read = getline(&curr_line, &len, file_ptr)) != -1)
	{
		line_num++;
		parse_line(curr_line, stack, line_num);
	}

	free(curr_line);
}
