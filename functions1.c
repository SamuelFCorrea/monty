#include "monty.h"

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

void mfail(void)
{
	status = EXIT_FAILURE;
	fprintf(stderr, "Error: malloc failed\n");
}

void pall(stack_t **head, unsigned int line)
{
	stack_t *tmp;
	(void)line;

	tmp = *head;
	
	for (; tmp; tmp = tmp->next)
		printf("%d\n", tmp->n);
}

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
