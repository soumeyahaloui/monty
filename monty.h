#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define DELIMS " \n\t\r"

/* Structures */
typedef struct stack_s
{
	int n;
	struct stack_s *next;
} stack_t;

/* Function prototypes */
void get_opcode_func(char *opcode, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
