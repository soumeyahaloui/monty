#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define DELIMS " \n\t\r"

/* Structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer value of the node
 * @next: pointer to the next node in the stack
 *
 * Description: doubly linked list node structure
 * for Monty stack, where the 'n' variable
 * represents the integer value of the node,
 * and 'next' is a pointer to the next node.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *next;
} stack_t;

/*
 * Struct: instruction_t
 * ---------------------
 * Description: Represents an instruction in a program.
 * Members: opcode (char*), f (function pointer)
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void get_opcode_func(char *opcode, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
