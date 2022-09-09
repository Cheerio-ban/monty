#include "monty.h"
/**
 * op_rotl - rotates the top element of the stack to the bottom
 * @head: Head of stack
 * @ln: line number
 */

void op_rotl(stack_t **head, unsigned int ln)
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
 * op_rotr - rotates the last element of the stack to the top
 * @head: head of the stack
 * @ln: line number
 */

void op_rotr(stack_t **head, unsigned int ln)
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

