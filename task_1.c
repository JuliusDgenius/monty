#include "monty.h"

/**
 * pint - Prints the top value of the stack/queue
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (!*stack)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}