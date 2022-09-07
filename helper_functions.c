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
