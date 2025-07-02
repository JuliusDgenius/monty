#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 *
 * Description:
 *   - Subtracts the top element from the second top element
 *   - Stores result in second top element
 *   - Removes the top element
 *   - If stack has <2 elements, prints error and exits
 */
void sub(stack_t **stack, unsigned int line_number)
{
int result;

/* Check if stack has at least two elements */
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

/* Perform subtraction: second_top - top */
result = (*stack)->next->n - (*stack)->n;

/* Store result in second top element */
(*stack)->next->n = result;

/* Remove top element */
pop(stack, line_number);
}
