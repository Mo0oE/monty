#include "monty.h"

/**
 * push_into_stack - A Function To Push New Node Into Stack
 * @node: The Node Struction To Push
 * @line: The Line Number
 */

void push_into_stack(stack_t **node, unsigned int line)
{
	stack_t *tmp_stack;
	(void)line;

	if (node == NULL)
	{
		free_all_node();
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
	{
		head = *node;
		return;
	}

	tmp_stack = head;
	head = *node;
	head->next = tmp_stack;
	tmp_stack->prev = head;
}

/**
 * print_stack - A Function To Print Elements In The Stack
 * @stack: The Stack To Print Its Elements
 * @line: The Line Number
 */

void print_stack(stack_t **stack, unsigned int line)
{
	stack_t *head;
	(void)line;

	if (stack == NULL)
	{
		free_all_node();
		exit(EXIT_FAILURE);
	}

	head = *stack;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * print_stack_top - A Function To Print The Top of The Stack
 * @stack: The Stack To Print Its Top Element
 * @line: The Line Number
 */

void print_stack_top(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_stack - A Function To Remove Top Element of Stack
 * @stack: The Stack To Print Its Top Element
 * @line: The Line Number
 */

void pop_stack(stack_t **stack, unsigned int line)
{
	stack_t *tmp_stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	tmp_stack = *stack;
	*stack = tmp_stack->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp_stack);
}

