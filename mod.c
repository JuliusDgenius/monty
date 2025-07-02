#include "monty.h"

/**
 * mul - computes the rest of the division of the second
 *  top element of the stack by the top element of the stack.
 * @stack: Double pointer to top of stack
 * @line_number: Current line number in bytecode file
 *
 * Description:
 *   - Compute rest of second top element by top element
 *   - Stores result in second top element
 *   - Removes top element
 */
void mod(stack_t **stack, unsigned int line_number)
{
int top_element, second_top, result;

/* Check for at least two elements */
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

divisor = (*stack)->n;
dividend = (*stack)->next->n;

if (divisor == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

result = divisor % dividend;

/* Store result in second top */
(*stack)->n = result;

/* Pop top element */
pop(stack, line_number);
}
