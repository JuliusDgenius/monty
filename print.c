#include "monty.h"

/**
 * _print - print int a top of stack
 * @stack: A pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _print(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't print, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}
