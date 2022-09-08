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
	(void) ln;
	print_stack(head);
}

/**
 * stack_pop - Removes the top element of the stack
 * @stack: Head of the stack
 * @ln: line number where the opcode is located
 */

void stack_pop(stack_t **head, unsigned int ln)
{
	int result;

	result = delete_stack_head(head);
	if (result != 1)
	{
		printf("L%d: can't pop an empty stack\n", ln);
		return;
	}
}

/**
 * stack_swap - swaps the top and second top element
 * @head: Head of stack
 * @ln: line number where opcode is located
 */
void stack_swap(stack_t **head, unsigned int ln)
{
	stack_t *ptr, *ptr2;
	int node_data;

	if (!*head || !(*head)->next)
	{
		printf("L%d: can't swap, stack too short\n", ln);
		return;
	}
	ptr = (*head);
	ptr2 = ptr->next;
	node_data = ptr->n;
	ptr->n = ptr2->n;
	ptr2->n = node_data;
}
