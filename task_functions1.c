#include "monty.h"

/**
 * stack_push - pushes a value to the stack
 * @head: the head of the stack linked list
 * @n: line number where the opcode is located
 */
void stack_push(stack_t **head, unsigned int n)
{
	add_to_stack(head, n);
}

void stack_pall(stack_t **head, unsigned int n)
{
	print_stack(head);
}
