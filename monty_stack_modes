#include "monty.h"

/**
 * monty_queue_mode - Sets the format of data to a stack(LIFO)
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_queue_mode(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *mode = malloc(sizeof(stack_t));

	if (mode == NULL)
		mallocerror();
	
	mode->n = QUEUE_MODE;
	mode->prev = NULL;
	mode->next = NULL;
	*stack = mode;
}

/**
 * monty_stack_mode - Sets the format of data to a stack(LIFO)
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_stack_mode(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *mode = malloc(sizeof(stack_t));

	if (mode == NULL)
		mallocerror();

	mode->n = STACK_MODE;
	mode->prev = NULL;
	mode->next = NULL;
	*stack = mode;
}

/**
 * monty_push_stack - Pushes a node in stack mode
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_push_stack(stack_t **stack)
{
	stack_t *new, *temp;

/*	printf("Mode: %d\n", (*stack)->n);*/
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(line_token[1]);
	temp = (*stack)->next;
	new->prev = *stack;
	new->next = temp;
	(*stack)->next = new;
	if (temp != NULL)
		temp->prev = new;
}

/**
 * monty_push_queue - Pushes a node in queue mode
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_push_queue(stack_t **stack)
{
	stack_t *new, *nav;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(line_token[1]);
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	nav = *stack;
	while (nav->next)
		nav = nav->next;
	new->prev = nav;
	nav->next = new;
}
