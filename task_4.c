#include "monty.h"

/**
 * add - Adds the top two elements of the stack/queue
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n += (*stack)->n;
pop(stack, line_number); /* Remove top element */
}

/**
 * nop - Does nothing
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
/* Do nothing */
}

/**
 * stack_mode - Sets global mode to stack (LIFO)
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
global.mode = STACK_MODE;
}

/**
 * queue_mode - Sets global mode to queue (FIFO)
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in bytecode file
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
global.mode = QUEUE_MODE;
}

/**
 * free_stack - Frees all nodes in the stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
stack_t *temp;

while (stack)
{
temp = stack;
stack = stack->next;
free(temp);
}
}
