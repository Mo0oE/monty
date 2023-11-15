#include "main.h"

/**
 * push_func - handle the push command
 * @stack: the stack
 * @line_number: the current line number
 * Description: Handles the push command
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Handle_errors()"); /* Create Handle_errors function */
		return;
	}

	if (!isdigit(*data.args[1]))
	{
		printf("Handle_errors()"); /* Create Handle_errors function */
		return;
	}

	new->n = atoi(data.args[1]);

	if (!*stack)
	{
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		new->prev = NULL;
	}
	*stack = new;
}
