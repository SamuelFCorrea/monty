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
