#include "monty.h"

/**
 * stack_push - pushes a value to the stack
 * @head: the head of the stack linked list
 * @n: line number where the opcode is located
 * @data: Node data
 */
void stack_push(stack_t **head, unsigned int ln, int data)
{
	int result;

	result = add_to_stack(head, data);
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
