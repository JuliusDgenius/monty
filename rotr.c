#include "monty.h"

/**
 * rotr - Rotates stack to bottom
 * @stack: Double pointer to top of stack
 * @line_number: Current line number
 *
 * Description:
 * - Last element becomes top
 * - Never fails
 */
void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *last, *second_last;
(void)line_number; /* Unused parameter */

if (!*stack || !(*stack)->next)
return; /* No rotation needed for 0-1 elements */

last = *stack;
while (last->next)
last = last->next;

second_last = last->prev;
second_last->next = NULL;

last->prev = NULL;
last->next = *stack;
(*stack)->prev = last;
*stack = last;
}
