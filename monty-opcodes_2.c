#include "monty.h"
/**
 * get_opcode - Matches instruction with corresponding function
 * @opcode: The instruction to match
 *
 * Return: A pointer to the matched opcode function
*/
void (*get_opcode(char *opcode))(stack_t **, unsigned int)
{
	instruction_t opcode_list[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack_mode},
		{"queue", monty_queue_mode},
		{NULL, NULL}
	};
	int i = 0;

	while (opcode_list[i].opcode)
	{
		if (strcmp(opcode, opcode_list[i].opcode) == 0)
		{
			return (opcode_list[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * count_elements - Counts the number of elements on the stack
 * @stack: Double pointer to the top of a stack_t linked list
 *
 * Return: Number of elements on the stack or 0 if stack is empty
*/
unsigned int count_elements(stack_t **stack)
{
	stack_t *nav;
	unsigned int stack_length = 0;

	if ((*stack)->next == NULL)
		return (stack_length);

	nav = (*stack)->next;
	while (nav->prev != NULL)
		nav = nav->prev;
	while (nav->next)
	{
		stack_length++;
		nav = nav->next;
	}
	return (stack_length);
}

/**
 * monty_nop - Does nothing, lol!
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_nop(__attribute__((unused))stack_t **stack,
									__attribute__((unused))unsigned int line_number)
{

}

/**
 * free_stack - Frees a stack_t stack
 * @stack: Double pointer to the top of a stack_t linked list
*/
void free_stack(stack_t **stack)
{
	stack_t *nav;

	nav = *stack;
	while (nav)
	{
		*stack = (*stack)->next;
		free(nav);
		nav = *stack;
	}
	*stack = NULL;
}
