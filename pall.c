#include "monty.h"

void push(stack_t **stack, unsigned int line_num)
{
    /* Parse the argument */
    int value = 0;
    /* ... Code to parse the argument using atoi or similar ... */

    /* Handle invalid argument */
    if (!valid_argument)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_num);
        exit(EXIT_FAILURE);
    }

    /* Create a new node and set its value */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;

    /* Insert the new node at the top of the stack */
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_num)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
