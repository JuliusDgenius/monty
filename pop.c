#include "monty.h"

/**
 * _pop - remove element from a list
 * @stack: pointer to first node
 * @line_number: integer
 * Return: void
 */
void _pop(stck_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}
