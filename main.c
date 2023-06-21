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
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;

	stack_t *stack = NULL;
	unsigned int line_number = 0;

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
