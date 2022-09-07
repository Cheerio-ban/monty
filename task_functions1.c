#include "monty.h"

/**
 * stack_push - pushes a value to the stack
 * @head: the head of the stack linked list
 * @n: line number where the opcode is located
 * @data: Node data
 */
void stack_push(stack_t **head, unsigned int ln)
{
	int result;
	char *ar;
	int arg;

	ar = strtok(NULL, " \t\n");
	arg = atoi(ar);

	result = add_to_stack(head, arg);
	if (result < 0)
	{
		printf("L%d: usage: push integer\n", ln);
		return;
	}
}

/**
 * stk_pall - prints all values of the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */


void stack_pall(stack_t **head, unsigned int ln)
{
	print_stack(head);
}

/**
 * stack_pop - Removes the top element of the stack
 * @stack: Head of the stack
 * @ln: line number where the opcode is located
 */

void stack_pop(stack_t **stack, unsigned int ln)
{
	int result;

	result = delete_stack_head(stack);
	if (result != 1)
	{
		printf("L%d: can't pop an empty stack\n", ln);
		return;
	}
}
