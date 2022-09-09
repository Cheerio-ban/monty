#include "monty.h"
#include  <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	char *f = argv[1];
	stack_t *stack;

	stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	get_opcodes(f, stack);
	return (0);
}