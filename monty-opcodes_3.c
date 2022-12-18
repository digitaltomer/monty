#include "monty.h"

/**
 * monty_pchar - Prints the char at the top of the stack
 * @stack: Double pointer to the top element of the stack
 * @line_number: Current line number
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top->n < 0 && top->n > 255)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}

/**
 * monty_pstr - prints each character of a stack to form a string
 * @stack: double pointer to the top element of the stack
 * @line_number: current line number
 */
void monty_pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *nav, *top = (*stack)->next;

	if (top == NULL)
	{
		printf("\n");
		return;
	}

	nav = top;
	while (nav)
	{	
		if ((nav->n < 0 && nav->n > 255) || nav->n == 0)
			break;
		printf("%c", nav->n);
		nav = nav->next;
	}
	printf("\n");
}

/**
 * monty_rotl - Makes the first element of the stack the last
 * @stack: double pointer to the top element of the stack
 * @line_number: current line number
 */
void monty_rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *nav, *temp, *head;
	unsigned int stack_length = count_elements(stack);

	if ((*stack)->next == NULL || stack_length < 2)
		return;
	head = (*stack)->next->next;
	temp = (*stack)->next;
	head->prev = *stack;
	(*stack)->next = head;

	nav = temp;
	while (nav->next)
		nav = nav->next;
	nav->next = temp;
	temp->prev = nav;
	temp->next = NULL;
}

/**
 * monty_rotr - Makes the last element of the stack the first
 * @stack: double pointer to the top element of the stack
 * @line_number: current line number
 */
void monty_rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *last, *temp, *temp2;
	unsigned int stack_length = count_elements(stack);

	if ((*stack)->next == NULL || stack_length < 2)
		return;

	last = *stack;
	temp2 = (*stack)->next;
	while (last->next)
		last = last->next;
	temp = last->prev;
	temp->next = NULL;
	last->prev = *stack;
	last->next = temp2;
	(*stack)->next = last;
	temp2->prev = last;
}
