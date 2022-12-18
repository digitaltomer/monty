#include "monty.h"

char **line_token = NULL;

/**
 * main - The starting point
 * @ac: keep track of argument count
 * @av: the argument vectors
 * Return: EXIT_SUCCESS (0)
*/

int main(int ac, char *av[])
{
	char *line = NULL;
	FILE *file;
	size_t line_size = 0;
	unsigned int line_number = 0;
	void (*opcode_function)(stack_t **, unsigned int);
	stack_t *stk = NULL;

	argcount(ac);

	file = fopen(av[1], "r");
	checkfile(file, av[1]);

	line = malloc(sizeof(char *));

	while (getline(&line, &line_size, file) != -1)
	{
		line_number++;
		line_token = tokenize(line);
		if (line_token == NULL)
		{
			if (check_empty_line(line, DELIMITERS) == 1)
				continue;
			else
				mallocerror();
		}
		if (line_token[0][0] == '#')
			continue;
		if (stk== NULL)
			monty_stack_mode(&stk, line_number);
		opcode_function = get_opcode(line_token[0]);
		if (opcode_function != NULL)
			opcode_function(&stk, line_number);
		else
			instructionerror(line_number);

	}
	free_stack(&stk);
	free(line_token);
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
