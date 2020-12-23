#include "monty.h"

/**
 * sub - subtracts the two first element of the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void sub(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*head)->next;
	tmp->n -= (*head)->n;
	tmp->prev = NULL;
	free(*head);
	*head = tmp;
}

/**
 * _div - divides the two first element of the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void _div(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't div stack too short\n", line);
		status = EXIT_FAILURE;
		return;
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*head)->next;
	tmp->n /= (*head)->n;
	tmp->prev = NULL;
	free(*head);
	*head = tmp;
}

/**
 * mul - multiplies the two first element of the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void mul(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*head)->next;
	tmp->n *= (*head)->n;
	tmp->prev = NULL;
	free(*head);
	*head = tmp;
}

/**
 * mod - multiplies the two first element of the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void mod(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		status = EXIT_FAILURE;
		return;
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*head)->next;
	tmp->n %= (*head)->n;
	tmp->prev = NULL;
	free(*head);
	*head = tmp;
}

/**
 * pchar - prints the char at the top of the stack
 * @head: stack head
 * @line: line number
 *
 * Return: none
 */

void pchar(stack_t **head, unsigned int line)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		status = EXIT_FAILURE;
		return;
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line);
		status = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*head)->n);
}
