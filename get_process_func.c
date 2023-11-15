#include "main.h"

/**
 * get_process_func - chosing the function to excute
 * @stack: the stack passed
 * @data: the program data
 * Return: 1 on failure 0 otherwise
*/

int get_process_func(stack_t **stack, prog_data data)
{
	instruction_t built_ins[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"nop", nop_func},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_ins + i)->opcode)
	{
		if (!strcmp((built_ins + i)->opcode, *data.args))
		{
			(built_ins + i)->f(stack, data.number_of_line);
			return (0);
		}
		i++;
	}
	printf("Handle_errors()"); /*creat Handle_errors func*/
	return (1);
}
