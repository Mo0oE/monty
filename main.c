#include "monty.h"

/**
 * main - Main Function of The Project
 * @argc: The Argument Counter
 * @argv: The Array of Arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execution_function(argv[1]);
	free_all_node();

	return (0);
}
