#include "monty.h"

/**
 * check_num_of_args - Checks the num of command-line arguments.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: void
 */
void check_num_of_args(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * op_file - Opens a file for reading.
 * @fname: The name of the file to open.
 * Return: A pointer to the file
 */
FILE *op_file(char *fname)
{
	FILE *file_ptr = fopen(fname, "r");

	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	return (file_ptr);
}

/**
 * clean_mem - clean up memory and closes a file.
 * @stack: A double pointer to the stack data structure.
 * @file_ptr: A pointer to the file being processed.
 * Return: void
 */
void clean_mem(stack_t **stack, FILE *file_ptr)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	fclose(file_ptr);
}

/**
 * main - Entry point
  * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *file_ptr;
	stack_t *stack = NULL;

	check_num_of_args(argc, argv);
	file_ptr = op_file(argv[1]);
	parse_file(file_ptr, &stack);
	clean_mem(&stack, file_ptr);

	return (0);
}
