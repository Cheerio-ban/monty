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

	if (value[1] == 0)
		result = add_to_stack(head, value[0]);
	else
		result = add_to_queue(head, value[0]);
	if (result < 0)
	{
		printf("L%d: usage: push integer\n", ln);
		value[2] = 1;
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
	int result;
	(void) ln;

	result = print_stack(stack);
	if (result != 0)
	{
		;
	}
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
		value[2] = 1;
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
		value[2] = 1;
		return;
	}
	ptr = (*head);
	ptr2 = ptr->next;
	node_data = ptr->n;
	ptr->n = ptr2->n;
	ptr2->n = node_data;
}
/**
 * stak_pint - print value at top of stack followed by new line
 * @head: head of stack
 * @ln: line number where the opcode is located
 */

void stack_pint(stack_t **head, unsigned int ln)
{
	stack_t *ptr;

	ptr = *head;
	if (ptr == NULL)
	{
		printf("L%d: can't pint, stack empty\n", ln);
		value[2] = 1;
		return;
	}

	printf("%d\n", ptr->n);
}
