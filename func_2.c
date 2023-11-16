#include "monty.h"

/**
 * swap_stack - A Function To Swap The Top 2 Elements of Stack
 * @stack: The Stack To Swap Its Elements
 * @line: The Number of The Line
 */

void swap_stack(stack_t **stack, unsigned int line)
{
	stack_t *tmp_stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_all_node();
		exit(EXIT_FAILURE);
	}

	tmp_stack = (*stack)->next;
	(*stack)->next = tmp_stack->next;

	if (tmp_stack->next != NULL)
		tmp_stack->next->prev = *stack;

	tmp_stack->next = *stack;
	(*stack)->prev = tmp_stack;
	tmp_stack->prev = NULL;
	*stack = tmp_stack;
}

/**
 * nop - A Function That Have No Operations
 * @stack: The Stack
 * @line: The Line Number
 */

void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
