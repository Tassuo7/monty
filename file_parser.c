#include "monty.h"

/**
 * parse_line - Parse a line of code.
 * @curr_line: The line of code to parse.
 * @stack: A pointer to the stack.
 * @line_num: The line number of the code.
 * Return: void
 */
int parse_line(char *curr_line, stack_t **stack, unsigned int line_num)
{
	char *opcode = strtok(curr_line, " \t\n"), *arg;
	int status = 0;

	if (opcode == NULL || opcode[0] == '#')
		return (0);

	arg = strtok(NULL, " \t\n");
	if (strcmp(opcode, "push") == 0)
		status = validate_push(arg, line_num);
	if (status == -1)
		return (-1);
	exe_instr(opcode, arg, stack, line_num);
	return (0);
}

/**
 * parse_file - Parse a file line by line
 * @file_ptr: A pointer to the file.
 * @stack: A pointer to the stack.
 * Return: void
 */
int parse_file(FILE *file_ptr, stack_t **stack)
{
	char *curr_line = NULL;
	size_t len = 0;
	unsigned int line_num = 0;
	ssize_t read;
	int status = 0;

	while ((read = getline(&curr_line, &len, file_ptr)) != -1)
	{
		line_num++;
		status = parse_line(curr_line, stack, line_num);
		if (status == -1)
		{
			free(curr_line);
			return (-1);
		}
	}

	free(curr_line);
	return (0);
}
