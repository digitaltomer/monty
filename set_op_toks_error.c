#include "monty.h"

/**
 * checkfile - hekcs if the file filed to open
 * @file: the expected file
 * @filename: the name of the file
*/
void checkfile(FILE *file, char *filename)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
/**
 * argcount - function to monitor the argunemnt count from main
 * @n: number of argument
*/
void argcount(int n)
{
	if (n != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * mallocerror - Prints if malloc fails
*/
void mallocerror(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
 * instructionerror - Prints if instruction is unkown
 * @n: line number
*/
void instructionerror(int n)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", n, line_token[0]);
	exit(EXIT_FAILURE);
}
