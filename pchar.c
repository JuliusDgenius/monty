#include "monty.h"

/**
 * pchar - Prints char at top of stack
 * @stack: Double pointer to top of stack
 * @line_number: Current line number
 *
 * Description:
 * - Prints char from top value's ASCII
 * - Handles empty stack and out-of-range values
 */
void pchar(stack_t **stack, unsigned int line_number)
{
int value;

if (!*stack)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

value = (*stack)->n;

/* Check ASCII range (0-127) */
if (value < 0 || value > 127)
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}

printf("%c\n", value);
}
