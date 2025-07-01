#include "monty.h"

/* Define our single allowed global variable */
global_t global = {STACK_MODE, 0};

#define BUFFER_SIZE 1024

/**
 * process_file - Processes Monty bytecode file
 * @file: File pointer to Monty bytecode file
 * @stack: Double pointer to the stack
 */
void process_file(FILE *file, stack_t **stack)
{
char buffer[BUFFER_SIZE];
unsigned int line_number = 0;

while (fgets(buffer, BUFFER_SIZE, file) != NULL)
{
char *opcode, *arg;
size_t len = strlen(buffer);
line_number++;

/* Remove trailing newline */
if (len > 0 && buffer[len - 1] == '\n')
buffer[len - 1] = '\0';

/* Skip empty lines and comments */
if (buffer[0] == '#' || buffer[0] == '\n' || buffer[0] == '\0')
continue;

/* Tokenize line to get opcode */
opcode = strtok(buffer, " \t");
if (!opcode)  /* Empty line after trimming */
continue;

/* Get argument if present */
arg = strtok(NULL, " \t");

/* Handle mode-changing opcodes */
if (strcmp(opcode, "stack") == 0)
global.mode = STACK_MODE;
else if (strcmp(opcode, "queue") == 0)
global.mode = QUEUE_MODE;
else
execute_opcode(opcode, arg, stack, line_number);
}
}

/**
 * main - Entry point for Monty bytecode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
FILE *file;
stack_t *stack = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

process_file(file, &stack);

fclose(file);
free_stack(stack);
return (EXIT_SUCCESS);
}

/**
 * is_valid_integer - Checks if a string represents a valid integer
 * @str: String to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_valid_integer(char *str)
{
if (!str || *str == '\0')
return (0);

/* Handle optional sign */
if (*str == '-' || *str == '+')
str++;

/* Check remaining characters */
while (*str)
{
if (!isdigit(*str))
return (0);
str++;
}

return (1);
}
