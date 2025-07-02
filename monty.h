#ifndef MONTY_H
#define MONTY_H

/* Include necessary standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global variable structure */
typedef struct global_s {
    int mode;           /* 0 = stack (LIFO), 1 = queue (FIFO) */
    int push_value;     /* Value for push operations */
} global_t;

extern global_t global;

/* Mode definitions */
#define STACK_MODE 0
#define QUEUE_MODE 1

/* Stack operations */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void stack_mode(stack_t **stack, unsigned int line_number);
void queue_mode(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

/* Linked list utilities */
stack_t *add_node(stack_t **stack, const int n);
stack_t *add_node_end(stack_t **stack, const int n);
void free_stack(stack_t *stack);

/* Core functionality */
void execute_opcode(char *opcode, char *arg, stack_t **stack, unsigned int line_number);
int is_valid_integer(char *str);

/* File processing */
void process_file(FILE *file, stack_t **stack);

#endif /* MONTY_H */