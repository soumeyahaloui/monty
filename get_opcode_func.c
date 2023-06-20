#include "monty.h"

/**
 * get_opcode_func - Selects the correct function to perform the operation
 *                   specified by opcode.
 * @opcode: Operation code.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the file being processed.
 */
void get_opcode_func(char *opcode, stack_t **stack, unsigned int line_number)
{
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

	int i = 0;

	while (instruction[i].opcode)
	{
		if (strcmp(instruction[i].opcode, opcode) == 0)
		{
			instruction[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
