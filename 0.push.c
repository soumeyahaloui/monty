#include "monty.h"

/**
 * isint - Check if a string is an integer.
 * @str: String to check.
 *
 * Return: 1 if the string is an integer, 0 otherwise.
 */

int isint(char *str);
/**
 * push - Pushes a value to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the file being processed.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, DELIMS);
	stack_t *new_node;

	if (!arg || !isint(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->next = *stack;
	*stack = new_node;
}
