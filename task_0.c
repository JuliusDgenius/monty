#include "monty.h"

/**
 * push - Pushes an element to the stack/queue
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 */
 void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

(void)line_number; /* Unused parameter */

/* Create new node */
new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
    
new_node->n = global.push_value;
new_node->prev = NULL;

/* Add node based on current mode */
if (global.mode == STACK_MODE) /* LIFO - add at head */
{
new_node->next = *stack;
if (*stack)
    (*stack)->prev = new_node;
*stack = new_node;
}
else /* QUEUE_MODE - FIFO - add at tail */
{
new_node->next = NULL;
if (!*stack)
{
    *stack = new_node;
}
else
{
stack_t *current = *stack;
while (current->next)
current = current->next;
current->next = new_node;
new_node->prev = current;
}
}
}

/**
 * pall - Prints all values in the stack/queue
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number; /* Unused parameter */

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
