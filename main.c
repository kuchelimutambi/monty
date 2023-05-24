#include "monty.h"

/**
 * main - main program running byte ocde
 * @argc: number of arguments
 * @argv: argument in matrix
 * Return: return exit success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	make_buffer(argv[1]);
	return (EXIT_SUCCESS);
}
