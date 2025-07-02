#include "monty.h"

/**
 * execute_opcode - Executes the given opcode command
 * @opcode: The operation code to execute
 * @arg: Argument for the opcode (if any)
 * @stack: Double pointer to the stack
 * @line_number: Current line number in bytecode file
 */
void execute_opcode(
char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
instruction_t instructions[] = {
{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
{"add", add}, {"nop", nop}, {"sub", sub}, {"div", div_op}, {"mod", mod},
{"mul", mul},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};

int i = 0;

/* Find matching opcode in instruction set */
while (instructions[i].opcode)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
/* Special handling for push instruction */
if (strcmp(opcode, "push") == 0)
{
if (!arg || !is_valid_integer(arg))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
global.push_value = atoi(arg);
}
instructions[i].f(stack, line_number);
return;
}
i++;
}

/* Invalid instruction */
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
free_stack(*stack);
exit(EXIT_FAILURE);
}
