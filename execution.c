#include "monty.h"

/**
 * execution_function - A Function To Read Commands From File
 * @file_name: The File To Read Commands From
 */

void execution_function(char *file_name)
{
	int line;
	size_t len = 0;
	FILE *file = fopen(file_name, "r");
	char *buf = NULL, *delimter = "\n ";
	char *operation_code, *operation_value;

	if (file == NULL || file_name == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free_all_node();
		exit(EXIT_FAILURE);
	}
	for (line = 1; getline(&buf, &len, file) != -1; line++)
	{
		operation_code = strtok(buf, delimter);
		if (buf == NULL || operation_code == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction\n", line);
			free_all_node();
			exit(EXIT_FAILURE);
		}
		operation_value = strtok(NULL, delimter);
		get_operation_func(operation_code, operation_value, line);
	}
	fclose(file);
}

/**
 * get_operation_func - A Function To Select Operation
 * @op_code: The Code of Selected Operation
 * @op_val: The Value To Pass To Operation
 * @line: The Number of The Line
 */

void get_operation_func(char *op_code, char *op_val, int line)
{
	int i;

	instruction_t list_function[] = {
		{"push", push_into_stack},
		{"pall", print_stack},
		{"pint", print_stack_top},
		{"pop", pop_stack},
		{"nop", nop},
		{"swap", swap_stack},
		{"add", add_stack_op},
		{"sub", sub_stack_op},
		{"mul", mul_stack_op},
		{"div", div_stack_op},
		{"mod", mod_stack_op},
		{NULL, NULL}};

	if (op_code[0] == '#')
		return;
	for (i = 0; list_function[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, list_function[i].opcode) == 0)
		{
			exe_op(list_function[i].f, op_code, op_val, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction\n", line);
	free_all_node(), exit(EXIT_FAILURE);
}

/**
 * exe_op - A Function To Execute The Operation
 * @fun: A Struct Function To Execute The Operation
 * @op_code: The Code of Selected Operation
 * @op_value: The Value To Pass To Operation
 * @line: The Number of The Line
 */

void exe_op(op_code_func fun, char *op_code, char *op_value, unsigned int line)
{
	int i;
	stack_t *node;

	if (strcmp(op_code, "push") == 0)
	{
		if (op_value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_all_node(), exit(EXIT_FAILURE);
		}
		for (i = 0; op_value[i] != '\0'; i++)
		{
			if (isdigit(op_value[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				free_all_node(), exit(EXIT_FAILURE);
			}
		}
		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_all_node(), exit(EXIT_FAILURE);
		}
		node->next = NULL;
		node->prev = NULL;
		node->n = atoi(op_value);
		fun(&node, line);
	}
	else
		fun(&head, line);
}
