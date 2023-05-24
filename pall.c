#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_t - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_t
{
    int n;
    struct stack_t *prev;
    struct stack_t *next;
} stack_t;

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the script file
 * @value: value to be pushed
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the script file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

int main(void)
{
    stack_t *stack = NULL;
    char *opcode = NULL;
    char *value_str = NULL;
    size_t size = 0;
    unsigned int line_number = 0;
    ssize_t read;

    while ((read = getline(&opcode, &size, stdin)) != -1)
    {
        line_number++;
        value_str = strtok(opcode, " \n\t");

        if (value_str == NULL || strcmp(value_str, "push") == 0)
        {
            value_str = strtok(NULL, " \n\t");
            if (value_str == NULL)
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }

            int value = atoi(value_str);
            if (value == 0 && strcmp(value_str, "0") != 0)
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }

            push(&stack, line_number, value);
        }
        else if (strcmp(value_str, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, value_str);
            exit(EXIT_FAILURE);
        }
    }

    free(opcode);
    return 0;
}
