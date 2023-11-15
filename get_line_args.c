#include "main.h"

/**
 * get_data_args - split the line into tokens
 * @data: the data struct
 * Return: 0 on success or 1 otherwise
*/

int get_data_args(prog_data data)
{
	char *tokens;
	int args_n = 4, i = 0;
	char *delimiters = " \n\t\a";

	data.args = malloc(args_n * sizeof(char *));

	if (!data.args)
		printf("Handle_errors()"); /*creat Handle_errors func*/

	tokens = strtok(data.line, delimiters);
	while (tokens)
	{
		data.args[i] = tokens;
		i++;
		if (i > args_n)
		{
			args_n *= 2;
			data.args = realloc(data.args, args_n);

			if (!data.args)
				printf("Handle_errors()"); /*creat Handle_errors func*/

		}
		tokens = strtok(NULL, delimiters);
	}
	data.args[i] = NULL;
	if (**data.args == '#')
		return (-1);
	return (0);
}
