#include "monty.h"

/**
 * mul - Multiplies the second top element by top element of stack
 * @stack: Double pointer to top of stack
 * @line_number: Current line number in bytecode file
 *
 * Description:
 *   - Multiplies second top element by top element
 *   - Stores result in second top element
 *   - Removes top element
 */
void mul(stack_t **stack, unsigned int line_number)
{
int top_element, second_top, result;

/* Check for at least two elements */
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

top_element = (*stack)->n;
second_top = (*stack)->next->n;

result = top_element *second_top;

/* Store result in second top */
(*stack)->next->n = result;

/* Pop top element */
pop(stack, line_number);
}
