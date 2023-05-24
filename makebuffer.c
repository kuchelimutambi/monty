#include "monty.h"
#include <stdio.h>

/**
 * make_buffer - make the buffer and parse through the file
 * @file_name: name of the file
 */
void make_buffer(char *file_name)
{
	size_t size = 0;
	FILE *file_input;
	char *str = NULL;
	unsigned int linenum = 1;
	stack_t *stack = NULL;
	char *command = NULL;

	file_input = fopen(file_name, "r");
	if (file_input == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	arg_holder.file = file_input;
	arg_holder.SQ = 1;
	while (getline(&str, &size, file_input) != -1)
	{
		arg_holder.input_str = str;
		if (*str == '\n')
		{
			linenum++;
			continue;
		}
		command = strtok(str, "\n\t ");
		if (command == NULL)
		{
			linenum++;
			continue;
		}
		arg_holder.arg = strtok(NULL, "\n\t ");
		opcode(command, linenum, &stack);
		linenum++;
	}
	free_stack(&stack);
}
