#include "monty.h"

/* Remove the redefinition of DELIMS since it's already defined in monty.h */

int getline(char **lineptr, size_t *n, FILE *stream);
int isint(char *str);

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	ssize_t nread;

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		line_number++;
		char *opcode = strtok(line, DELIMS);

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, line_number);
			}
			/* Add other opcode handling here */
		}
	}

	free(line);
	return (0);
}

/**
 * push - Pushes a value to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction in the file being processed.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, DELIMS);

	if (!arg || !isint(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * isint - Check if a string is an integer.
 * @str: String to check.
 *
 * Return: 1 if the string is an integer, 0 otherwise.
 */
int isint(char *str)
{
	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}

	return (1);
}
