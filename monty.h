#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * @brief 
 * 
 *
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* helper_functions.c */
int add_to_stack(stack_t **head, int n);
void free_stack(stack_t *head);
int delete_stack_head(stack_t **head);
int print_stack(stack_t **head);
int delete_stack_end(stack_t **head);

/* task_functions1.c */
void stack_push(stack_t **head, unsigned int ln);
void stack_pall(stack_t **head, unsigned int ln);
void stk_swap(stack_t **head, unsigned int ln);
void stack_pop(stack_t **head, unsigned int ln);
void get_opcodes(char *filename, stack_t *stack);
void (*get_opcode_func(char *s))(stack_t **stack, unsigned int n);

#endif
