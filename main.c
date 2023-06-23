#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode = strtok(line, DELIMS);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		char *opcode = strtok(line, DELIMS);

		if (opcode && opcode[0] != '#')
		{
			get_opcode_func(opcode, &stack, line_number);
		}
	}

	free_stack(stack);
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees a doubly linked list (a stack)
 * @head: Pointer to the head of the stack
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;

	while (current)
	{
		stack_t *temp = current;
		current = current->next;
		free(temp);
	}
}
