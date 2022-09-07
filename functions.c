#include "monty.h"
#include  <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void get_opcodes(char *filename)
{
	FILE *f;
	ssize_t n;
	char *opcodes, *opcode, *arg, **op_command;
	size_t len = 0, i = 0;
	int line_no = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	if ((f = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}
	

	while((n = getline(&opcodes, &len, f)) >= 0)
	{
		opcode = strtok(opcodes, " \t\n");
		if (strcmp(opcode, "push") != 0)
		{
			f = get_opcode(opcode);
			if (f == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s", line_no, opcode);
				exit(EXIT_FAILURE);
			}
			f(&stack, line_no);
		}
		else
		{
			arg = strtok(NULL, " \t\n");
			f = get_opcode(opcode);
		}
		
	}
}

/**
char **get_commands(char *s)
{
	char **tokens;
	char *token;
	int i = 1;

	token = strtok(s, " \t\n");
	if (strcmp(token, "push") != 0)
	{
		tokens = malloc(sizeof(char *) * 1);
		tokens[0] = token;
	}
	printf("%s\n", tokens[0]);
	/**
	else
	{
		return (NULL);	
	}
	
	
	
	while (token != NULL)
	{
		token = strtok(NULL, " \n");
		i++;
		tokens[i] = token;
	}
	i++;
	tokens[i] = token;

	return (tokens);

}
*/