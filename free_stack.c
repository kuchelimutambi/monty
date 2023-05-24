#include "monty.h"
/**
 * free_stack - free the stack and the str input
 * @head: input list pointer
 */
void free_stack(stack_t **head)
{
	stack_t *current;

	if (head == NULL)
		return;
	free(arg_holder.input_str);
	fclose(arg_holder.file);
	while (*head != NULL)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
}
