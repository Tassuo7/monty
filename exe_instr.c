#include "main.h"
int VALUE_TO_PUSH = 0;
/**
 * get_instr - Get the instruction for opcode
 * @opcode: The opcode
 * @insts: The instructions
 * Return: A pointer to the instr
 */
instruction_t *get_instr(char *opcode, instruction_t *instrs)
{
	int idx;

	for (idx = 0; instrs[idx].opcode != NULL; ++idx)
	{
		if (strcmp(opcode, instrs[idx].opcode) == 0)
			return (&instrs[idx]);
	}
	return (NULL);
}


/**
 * exe_instr - Execute an instruction
 * @opcode: The opcode
 * @arg: The argument for the opcode
 * @stack: The stack
 * @line_num: The line number of the instruction
 */
void exe_instr(char *opcode, char *arg, stack_t **stack, unsigned int line_num)
{
	instruction_t *instr;
	instruction_t instrs[] =  {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	instr = get_instr(opcode, instrs);

	if (instr != NULL)
	{
		if (strcmp(opcode, "push") == 0)
			VALUE_TO_PUSH = atoi(arg);
		instr->f(stack, line_num);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
}
