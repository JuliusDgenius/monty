#include "monty.h"

/**
 * div_op - Divides second top element by top element of stack
 * @stack: Double pointer to top of stack
 * @line_number: Current line number in bytecode file
 *
 * Description:
 *   - Divides second top element by top element
 *   - Stores result in second top element
 *   - Removes top element
 *   - Handles division by zero
 *   - Handles stack too short
 */
void div_op(stack_t **stack, unsigned int line_number)
{
int dividend, divisor, result;

/* Check for at least two elements */
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

divisor = (*stack)->n;          /* Top element (divisor) */
dividend = (*stack)->next->n;   /* Second top element (dividend) */

/* Check for division by zero */
if (divisor == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

/* Perform division */
result = dividend / divisor;

/* Store result in second top element */
(*stack)->next->n = result;

/* Remove top element */
pop(stack, line_number);
}
