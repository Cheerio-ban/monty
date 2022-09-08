#include "monty.h"

/**
 * stack_add - adds top two elements
 * @head: Head of stack
 * @ln: Line number of opcode
 */

void stack_add(stack_t **head, unsigned int ln)
{
	stack_t ptr;
	stack_t ptr2;

	if (!*head || !*head.next)
	{
		printf("L%d: can't add, stack too short\n", ln);
		return;
	}
	ptr = (*head);
	ptr2 = ptr->next;
	ptr->n = ptr->next->n + ptr->n;
	ptr->next = ptr2->next;
	if (ptr2->next)
		ptr2->next->prev = ptr;
	else
		ptr->next = NULL;
	free(ptr2);
}

/**
 * stack_nop - Does nothing
 * @head: Head of stack
 * @ln: line number where opcode is located
 */
void stack_nop(stack_t **head, unsigned int ln)
{
	(void) head;
	(void) ln;
}

/**
 * stack_sub - Subtracts top two elements
 * @head: Head of stack
 * @ln: Line number of opcode
 */

void stack_sub(stack_t **head, unsigned int ln)
{
	stack_t ptr, ptr2;

	if (!*head || !*head.next)
	{
                printf("L%d: can't add, stack too short\n", ln);
                return;
	}
	ptr = (*head);
	ptr2 = ptr.next;
	ptr->n = ptr2->n - ptr->n;
	ptr->next = ptr2->next;
	if (ptr2->next)
		ptr2->next->prev = ptr;
	else
		ptr->next = NULL;
	free(ptr2);
}
