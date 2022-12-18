#include "monty.h"

/**
 * monty_push - Pushes an element to the stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_push(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (line_token[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (line_token[1][i])
	{
		if (i == 0 && line_token[1][i] == '-')
		{
			i++;
			continue;
		}
		if (line_token[1][i] < '0' || line_token[1][i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if ((*stack)->n == QUEUE_MODE)
		monty_push_queue(stack);
	else
		monty_push_stack(stack);
}

/**
 * monty_pall - Prints all the values on a stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *nav;

	if (*stack == NULL)
		return;

	nav = (*stack)->next;
	while (nav)
	{
		printf("%d\n", nav->n);
		nav = nav->next;
	}
/*	printf("-----------\n");*/
}

/**
 * monty_pint - Prints the value at the top of a stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *nav;

	if (count_elements(stack) < 1)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	nav = (*stack)->next;

	printf("%d\n", nav->n);
	/*printf("-----------\n");*/
}

/**
 * monty_pop - Removes the top element of a stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nav;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	nav = (*stack)->next;
	while (nav->prev != NULL)
		nav = nav->prev;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(nav);
}

/**
 * monty_swap - Swaps the two top elements of the stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *nav, *temp;
	unsigned int stack_length = count_elements(stack);

	if (stack_length < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	nav = temp->next;
	nav->prev = *stack;
	temp->next = nav->next;
	nav->next = temp;
	temp->next->prev = temp;
	temp->prev = nav;
	(*stack)->next = nav;
}
