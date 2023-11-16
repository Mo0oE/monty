#include "monty.h"

/**
 * add_stack_op - A Function To Sum First 2 Elements
 * @stack: The Stack To Perform Operation On
 * @line: The Number of Line
 */

void add_stack_op(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;

	(*stack) = (*stack)->next;
	(*stack)->n = result;

	free((*stack)->prev);
}

/**
 * sub_stack_op - A Function To Sub First 2 Elements
 * @stack: The Stack To Perform Operation On
 * @line: The Number of Line
 */

void sub_stack_op(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;

	(*stack) = (*stack)->next;
	(*stack)->n = result;

	free((*stack)->prev);
}

/**
 * mul_stack_op - A Function To Multiply First 2 Elements
 * @stack: The Stack To Perform Operation On
 * @line: The Number of Line
 */

void mul_stack_op(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;

	(*stack) = (*stack)->next;
	(*stack)->n = result;

	free((*stack)->prev);
}

/**
 * div_stack_op - A Function To Divide First 2 Elements
 * @stack: The Stack To Perform Operation On
 * @line: The Number of Line
 */

void div_stack_op(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;

	(*stack) = (*stack)->next;
	(*stack)->n = result;

	free((*stack)->prev);
}

/**
 * mod_stack_op - A Function To Get Remainder of First 2 Elements
 * @stack: The Stack To Perform Operation On
 * @line: The Number of Line
 */

void mod_stack_op(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;

	(*stack) = (*stack)->next;
	(*stack)->n = result;

	free((*stack)->prev);
}

