#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

instruction_t instruction[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}
};

/**
 * get_op_func - Selects the correct function to perform the operation
 *               specified by opcode.
 * @opcode: Operation code.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the file being processed.
 *
 * Return: Pointer to the function that corresponds to the opcode.
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	while (instruction[i].opcode)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
			return (instruction[i].f);
		i++;
	}
	return (NULL);
}
