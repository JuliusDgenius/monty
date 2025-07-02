#include "monty.h"

/**
 * pstr - Prints string from stack
 * @stack: Double pointer to top of stack
 * @line_number: Current line number
 *
 * Description:
 * - Prints characters until NULL, 0, or invalid ASCII
 * - Empty stack prints only newline
 */
void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number; /* Unused parameter */

while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
{
printf("%c", current->n);
current = current->next;
}
printf("\n");
}
