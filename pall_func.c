#include "main.h"

/**
 * pall_func - handle the pall command
 * @stack: the stack
 * @line_number: the current line number
 * Description: handles the pall command
*/

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;

	while (current)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}
