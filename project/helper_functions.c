#include "monty.h"

/**
 * add_to_stack - Adds element to stack
 * @head: Head of stack
 * @n: Number to be added to stack
 *
 * Return: 1 (success), -1 (Failure)
 */
int add_to_stack(stack_t **head, int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	newNode->n = n;
	newNode->prev = NULL;
	if (*head == NULL)
	{
		newNode->next = NULL;
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		(*head)->prev = newNode;
		*head = newNode;
	}
	return (1);
}

/**
 * free_stack - Frees all elements in a stack
 * @head: head of the stack
 */

void free_stack(stack_t *head)
{
	stack_t *ptr;

	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

/**
 * delete_stack_head - deletes the head node of the stack
 * @head: head of the stack
 * Return: 1 (Success), -1 (Failure)
 */

int delete_stack_head(stack_t **head)
{
	stack_t *ptr;

	if (*head == NULL)
		return (-1);
	ptr = (*head);
	if (ptr->next == NULL)
	{
		free(ptr);
		(*head) = NULL;
		return (1);
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(ptr);
	return (1);
}

/**
 * print_stack - Prints elements in a stack
 * @head: Head of the stack
 * Return: 1 (Success), -1 (Failure)
 */

int print_stack(stack_t **head)
{
	stack_t *ptr;

	ptr = (*head);
	if (ptr == NULL)
		return (-1);
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	return (0);
}

/**
 * delete_stack_end - deletes a node at stack's end
 * @head: head of stack
 * Return: 1 (Success) and, -1 (Failure)
 */

int delete_stack_end(stack_t **head)
{
	stack_t *ptr;

	if (*head == NULL)
		return (-1);
	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->prev->next = NULL;
	free(ptr);
	return (1);
}

