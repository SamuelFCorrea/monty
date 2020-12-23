#include "monty.h"

/**
 * push - puts a new element in the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void push(stack_t **head, unsigned int line)
{
	stack_t *new;

	is_num();

	if (status == EXIT_FAILURE)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		return;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		mfail();
		return;
	}
	new->n = atoi(argument.arg);
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}

/**
 * is_num - ins the argument isn't a number change the program status
 *
 * Return: none
 */


void is_num(void)
{
	int i;

	if (!argument.arg)
	{
		status = EXIT_FAILURE;
		return;
	}
	for (i = 0; *(argument.arg + i); i++)
		if (*(argument.arg + i) > 47 && *(argument.arg + i) < 58)
			continue;
		else
		{
			status = EXIT_FAILURE;
			return;
		}
}

/**
 * mfail - change the program status and print the message
 *
 * Return: none
 */

void mfail(void)
{
	status = EXIT_FAILURE;
	fprintf(stderr, "Error: malloc failed\n");
}

/**
 * pall - print all the elements in the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void pall(stack_t **head, unsigned int line)
{
	stack_t *tmp;
	(void)line;

	tmp = *head;

	for (; tmp; tmp = tmp->next)
		printf("%d\n", tmp->n);
}

/**
 * free_stack - free all the stack
 * @head: stack head
 *
 * Return: none
 */

void free_stack(stack_t *head)
{
	stack_t *f = head;

	while (head)
	{
		head = head->next;
		free(f);
		f = head;
	}
	free(f);
}
