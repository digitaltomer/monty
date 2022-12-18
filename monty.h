#ifndef _MONTY_H_
#define _MONTY_H_
#define  _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define DELIMITERS "  \a\t\b\n"
extern char **line_token;
#define QUEUE_MODE 1
#define STACK_MODE 0


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **tokenize(char *line);
void monty_push(stack_t **stack, unsigned int line_number);
int check_empty_line(char *line, char *delimiter);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void (*get_opcode(char *opcode))(stack_t **, unsigned int);
void monty_swap(stack_t **stack, unsigned int line_number);
unsigned int count_elements(stack_t **stack);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void checkfile(FILE *file, char *filename);
void argcount(int n);
void mallocerror(void);
void instructionerror(int n);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, __attribute__((unused))unsigned int line_number);
void monty_rotr(stack_t **stack, __attribute__((unused))unsigned int line_number);
void monty_push_stack(stack_t **stack);
void monty_push_queue(stack_t **stack);
void monty_queue_mode(stack_t **stack, __attribute__((unused))unsigned int line_number);
void monty_stack_mode(stack_t **stack, __attribute__((unused))unsigned int line_number);
void instructionerror(int n);
void mallocerror(void);
void argcount(int n);
void checkfile(FILE *file, char *filename);
#endif
