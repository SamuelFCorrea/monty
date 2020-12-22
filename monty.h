#ifndef MONTY_H
#define MONTY_H


/**********************************Headers************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/***********************************Macros************************************/

#define B_SIZE 1024

/*********************************Structures**********************************/


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct DATA - all the data required to the excution
 * @line: line number
 * @fn: file name
 * @fd: file descriptor
 *
 * Description: contains all the memory allocation to
 * facilitate the free prosses
 */

typedef struct data_s
{
	unsigned int line;
	char *line_buffer;
	char *file_name;
	FILE *file;
} data_t;

extern int status;

/********************************Prototipes*********************************/

data_t *init(char *);
void s_and_e(data_t *);
void pall(stack_t **, unsigned int);
void free_data_t(data_t *);
void push(stack_t **, unsigned int, char *);
void bucle(stack_t **, data_t *, instruction_t *);
void free_stack(stack_t *);
void push(stack_t **, unsigned int, char *);

/***************************************************************************/

#endif
