#include "monty.h"

/**
 * pop - Removes the top element of the stack/queue
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!*stack)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;
if (*stack)
(*stack)->prev = NULL;
free(temp);
}