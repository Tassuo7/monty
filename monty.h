#ifndef _MAIN_H_
#define _MAIN_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

extern int VALUE_TO_PUSH;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct operation_s - validator its function
 * @opcode: the opcode
 * @validate_func: function to handle the opcode
 * Description: validator and its function
 */
typedef struct operation_s
{
	char *opcode;
	int (*validate_func)(char *arg, unsigned int);
} operation_t;


/*Functions*/
void check_num_of_args(int argc, char *argv[]);
FILE *op_file(char *fname);
void clean_mem(stack_t **stack, FILE *file_ptr);
int parse_line(char *curr_line, stack_t **stack, unsigned int line_num);
int parse_file(FILE *file_ptr, stack_t **stack);
instruction_t *get_instr(char *opcode, instruction_t *instrs);
void exe_instr(char *opcode,
char *arg, stack_t **stack, unsigned int line_num);


/*Validators*/
int validate_args(char *opcode, char *arg, unsigned int line_number);
int validate_push(char *arg, unsigned int line_number);
int validate_pall(char *arg, unsigned int line_number);
int validate_pint(char *arg, unsigned int line_number);
int validate_pop(char *arg, unsigned int line_number);
int validate_swap(char *arg, unsigned int line_number);
int validate_add(char *arg, unsigned int line_number);
int validate_nop(char *arg, unsigned int line_number);
int validate_pchar(char *arg, unsigned int line_number);
int validate_pstr(char *arg, unsigned int line_number);
int validate_rotl(char *arg, unsigned int line_number);
int validate_rotr(char *arg, unsigned int line_number);
int validate_sub(char *arg, unsigned int line_number);
int validate_div(char *arg, unsigned int line_number);
int validate_mod(char *arg, unsigned int line_number);
int validate_mul(char *arg, unsigned int line_number);

/*Stack functions*/
void _push(stack_t **stack, unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _pchar(stack_t **stack, unsigned int line_num);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);

#endif
