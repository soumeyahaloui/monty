#include "monty.h"

void process_file(FILE *file);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_file(file);

	fclose(file);
	return (0);
}

void process_file(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		char *opcode = strtok(line, DELIMS);

		if (opcode && opcode[0] != '#')
			execute_opcode(opcode, &stack, line_number);

		line_number++;
	}

	free(line);
}

void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	void (*func)(stack_t **, unsigned int) = get_op_func(opcode);

	if (func)
		func(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
