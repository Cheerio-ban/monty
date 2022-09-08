#include "monty.h"
#include  <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void get_opcodes(char *filename, stack_t *stack)
{
	FILE *f;
	ssize_t n;
	char *opcodes, *opcode, *arg;
	size_t len = 0;
	unsigned int line_no = 1;
	void (*g)(stack_t **stack, unsigned int line_number);

	if ((f = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}
	

	while((n = getline(&opcodes, &len, f)) >= 0)
	{

		opcode = strtok(opcodes, " \t\n");
		if (!(opcode))
		{
			line_no++;
			continue;
		}
		g = get_opcode_func(opcode);
		if (g == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, opcode);
			exit(EXIT_FAILURE);
		}
		g(&stack, line_no);
		line_no++;
	}

	fclose(f);
}