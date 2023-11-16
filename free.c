#include "monty.h"
stack_t *head = NULL;

/**
 * free_all_node - A Function To Free Allocated Space
 */

void free_all_node(void)
{
	stack_t *tmp_stack;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp_stack = head;
		head = head->next;
		free(tmp_stack);
	}
}
