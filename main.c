#include "main.h"


/**
 * main - entering point
 * @argc: args counter
 * @argv: args values
 * Return: don't know yet
*/

int main(int argc, char **argv)
{
	size_t line_length = 0, line_get = 1;
	stack_t *stack = NULL;

	memset((void *) &data, 0, sizeof(data));

	if (argc != 2)
		printf("Handle_errors()"); /*creat handle_errors func*/

	data.file_name = argv[1];
	data.fp = fopen(data.file_name, "r");

	if (!data.fp)
		printf("Handle_error()"); /*creat handle_errors func*/

	while ((line_get = getline(&data.line, &line_length, data.fp)) > 0)
	{
		if (!data.line || *data.line == '\n')
			continue;

		free(data.args);

		if (get_data_args(data) < 0)
			continue;

		if (*data.args == NULL)
			continue;

		get_process_func(&stack, data);
	}
	free_data(data);
	free_the_stack(stack);
	return (EXIT_SUCCESS);
}
