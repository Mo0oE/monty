#include "main.h"

/**
 * free_data - frees the data struct
 * @data: the data struct
 * Description: free
*/

void free_data(prog_data data)
{
	free(data.line);
	free(data.args);
	fclose(data.fp);
}

/**
 * free_the_stack - frees the stack!
 * @stack: the stack to be freed
 * Description: free
*/

void free_the_stack(stack_t *stack)
{
	stack_t *current = NULL;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
