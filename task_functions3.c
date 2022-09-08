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
