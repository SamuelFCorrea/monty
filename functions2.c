#include "monty.h"

/**
 * pint - print the top of the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void pint(stack_t **head, unsigned int line)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		status = EXIT_FAILURE;
		return;
	}

	printf("%d\n", (*head)->n);
}

/**
 * pop - remove the top of the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void pop(stack_t **head, unsigned int line)
{
	stack_t *tmp = NULL;

	if (!head || !*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		status = EXIT_FAILURE;
		return;
	}
	tmp = (*head)->next;
	free(*head);
	*head = tmp;
	if (*head)
		tmp->prev = NULL;
}

/**
 * swap - change the position of two first elements
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void swap(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		status = EXIT_FAILURE;
		return;
	}
	tmp = (*head)->next;
	(*head)->prev = tmp;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	tmp->prev = NULL;
}
