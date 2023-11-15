#include "main.h"

/**
 * pint_func - to handle the pint command
 * @stack: the stack
 * @line_number: the current line number
 * Description: None
*/

void pint_func(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (!*stack)
		printf("Handle_error()"); /*creat Handle_error func*/

	fprintf(stdout, "%i\n", (*stack)->n);
}
