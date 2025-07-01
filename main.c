#include "monty.h"

/* Define our single allowed global variable */
global_t global = {STACK_MODE, 0};

#define BUFFER_SIZE 1024

/**
 * main - Entry point for Monty bytecode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char buffer[BUFFER_SIZE];
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    
    /* Check argument count */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open Monty bytecode file */
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read file line by line */
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
        {
            global.mode = STACK_MODE;
            continue;
        }
        else if (strcmp(opcode, "queue") == 0)
        {
            global.mode = QUEUE_MODE;
            continue;
        }

        /* Execute the opcode */
        execute_opcode(opcode, arg, &stack, line_number);
    }

    /* Cleanup resources */
    fclose(file);
    free_stack(stack);
    return (EXIT_SUCCESS);
}

/**
 * execute_opcode - Executes the given opcode command
 * @opcode: The operation code to execute
 * @arg: Argument for the opcode (if any)
 * @stack: Double pointer to the stack
 * @line_number: Current line number in bytecode file
 */
void execute_opcode(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
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

/**
 * is_valid_integer - Checks if a string represents a valid integer
 * @str: String to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_valid_integer(char *str)
{
    if (!str || *str == '\0')
        return 0;
    
    /* Handle optional sign */
    if (*str == '-' || *str == '+')
        str++;
    
    /* Check remaining characters */
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    
    return 1;
}