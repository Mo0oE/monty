#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

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

extern stack_t *head;

typedef void (*op_code_func)(stack_t **, unsigned int);

/* Func_1.c File: */
void push_into_stack(stack_t **node, unsigned int line);
void print_stack(stack_t **stack, unsigned int line);
void print_stack_top(stack_t **stack, unsigned int line);
void pop_stack(stack_t **stack, unsigned int line);

/* Func_2.c File: */
void nop(stack_t **stack, unsigned int line);
void swap_stack(stack_t **stack, unsigned int line);

/* Func_op.c File: */
void add_stack_op(stack_t **stack, unsigned int line);
void sub_stack_op(stack_t **stack, unsigned int line);
void mul_stack_op(stack_t **stack, unsigned int line);
void div_stack_op(stack_t **stack, unsigned int line);
void mod_stack_op(stack_t **stack, unsigned int line);

/* Execution.c File: */
void execution_function(char *file_name);
void get_operation_func(char *op_code, char *op_val, int line);
void exe_op(op_code_func fun, char *op_code, char *op_value, unsigned int line);

/* Free.c File: */
void free_all_node(void);

#endif
