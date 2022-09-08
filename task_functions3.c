#include "monty.h"
/**
 * stack_mod - mod top two element in a stack
 * @head: Head of stack
 * @ln: Line number of opcode;
 */
void stack_mod(stack_t **head, unsigned int ln)
{
	stack_t *ptr, *ptr2;

	if (!*head || !*head->next)
	{
		printf("L%d: can't mod, stack too short\n", ld);
		return;
	}
	ptr = *head;
	ptr2 = ptr->next;
	if (ptr->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		return;
	}
	ptr->n = ptr2->n % ptr->n;
	ptr->next = ptr2->next;
	if (ptr2->next)
		ptr2->next->prev = ptr;
	else
		ptr->next = NULL;
	free(ptr2);
}

/**
 * stack_rotl - rotates the top element of the stack to the bottom
 * @head: Head of stack
 * @ln: line number
 */

void stack_rotl(stack_t **head, unsigned int ln)
{
	stack_t *ptr, *ptr2;

	(void) ln;
	ptr = (*head);
	if (ptr == NULL)
		return;
	ptr2 = ptr;
	if (ptr->next == NULL)
		;
	else
	{
		(*head) = (*head)->next;
		while (ptr2->next)
			ptr2 = ptr2->next;
		ptr2->next = ptr;
		ptr->prev = ptr2;
		ptr->next->prev = NULL;
		ptr->next = NULL;
	}
}

/**
 * stack_rotr - rotates the last element of the stack to the top
 * @head: head of the stack
 * @ln: line number
 */

void stack_rotr(stack_t **head, unsigned int ln)
{
	stack_t *ptr, *ptr2;

	(void) ln;
	ptr = (*head);
	if (ptr == NULL)
		return;
	ptr2 = ptr;
	if (ptr->next == NULL)
		;
	else
	{
		while (ptr2->next != NULL)
			ptr2 = ptr2->next;
		ptr2->prev->next = NULL;
		ptr2->prev = NULL;
		ptr2->next = ptr;
		ptr->prev = ptr2;
		(*head) = ptr2;
	}
}
