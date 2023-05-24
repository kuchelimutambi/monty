#include "monty.h"

/**
 * opcode - check for operation code
 * @command: cammand input
 * @line_num: line number
 * @stack: stack of memory
 */
void opcode(char *command, unsigned int line_num, stack_t **stack)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (command[0] == '#')
	{
		return;
	}
	if (strcmp(command, "stack") == 0)
	{
		arg_holder.SQ = 1;
		return;
	}
	if (strcmp(command, "queue") == 0)
	{
		arg_holder.SQ = 0;
		return;
	}
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, command) == 0)
		{
			ops[i].f(stack, line_num);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_num, command);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
