#include "monty.h"

/**
 * get_opcode_func - gets the right operation
 * @s: opcode passed to the program
 * Return: A pointer to an opcode function, NULL if not valid
 */
void (*get_opcode_func(char *s))(stack_t **stack, unsigned int n)
{
	int i;
	instruction_t stak[] = {
		{"pall", stack_pall},
		{"push", stack_push},
		/*{"pop", stack_pop},
		{"add", stack_add},
		{"swap", stack_swap},
		{"pint", stack_pint},
		{"nop", stack_nop},
		{"pchar", stack_pchar},
		{"pstr", stack_pstr},
		{"rotr", stack_rotr},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{"mod", stack_mod},
		{"queue", stack_queue},
		{"stack", stack_stack},*/
		{NULL, NULL}
	};

	i = 0;
	while (i < 17)
	{
		if (strcmp(s, (stak[i]).opcode) == 0)
		{
			return (*(stak[i]).f);
		}
		i++;
	}
	return (NULL);
}
