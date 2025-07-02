#include "monty.h"

/**
 * rotl - Rotates stack to top
 * @stack: Double pointer to top of stack
 * @line_number: Current line number
 *
 * Description:
 * - Top element becomes last
 * - Second top becomes first
 * - Never fails
 */
void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *top, *second, *last;
(void)line_number; /* Unused parameter */

if (!*stack || !(*stack)->next)
return; /* No rotation needed for 0-1 elements */

top = *stack;
second = top->next;
last = top;

/* Find last element */
while (last->next)
last = last->next;

/* Perform rotation */
*stack = second;
second->prev = NULL;

last->next = top;
top->prev = last;
top->next = NULL;
}
