#ifndef MAIN_H
#define MAIN_H

/*includes*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

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
 * struct data_s - the struct of all data
 * @args: the arguments
 * @file_name: the name of input file
 * @number_of_line: the number of current number
 * @line: the content of the line
 * @fp: the file
 * Descriptoin: a struct!
*/
typedef struct data_s
{
	char **args;
	char *file_name;
	FILE *fp;
	unsigned int number_of_line;
	char *line;
} prog_data;

prog_data data;

/*functions*/
void free_data(prog_data data);
void free_the_stack(stack_t *stack);
int get_data_args(prog_data data);
int get_process_func(stack_t **stack, prog_data data);



/*built_ins*/
void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);



#endif
