#include "monty.h"

int status = 0;
/**
 * pall - print all the values on the stack
 * @head: head of the stack
 * @line: line of the file
 *
 * Return: none
 */

void pall(stack_t **head, unsigned int line)
{
	stack_t *tp = NULL;
	(void)line;

	if (!head || !*head)
		return;

	tp = *head;

	for (; tp;)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
	}
}

/**
 * free_stack - free the stack
 * @head: <<
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

/**
 * push - push a new element into the stack
 * @head: <<
 * @line: <<
 * @data: int to put in the stack
 *
 * Return: none
 */

void push(stack_t **head, unsigned int line, char *data)
{
	int i;
	stack_t *new = NULL;

	for (i = 0; *(data + i); i++)
		if (*(data + i) < 48 || *(data + i) > 57)
		{
			i = -1;
			break;
		}
	if (!data || i == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		status = 1;
	}
	else
	{
		new = malloc(sizeof(stack_t));
		if (!new)
		{
			fprintf(stderr, "Error: malloc failed\n");
			status = 1;
			return;
		}
		new->n = atoi(data);
		new->next = *head;
		new->prev = NULL;
		if (*head != NULL)
			(*head)->prev = new;
		*head = new;
	}
}

/**
 * s_and_e - execute the correct function
 * @data: struct with important data
 *
 * Return: none
 */

void s_and_e(data_t *data)
{
	stack_t **head = NULL;
	int i;
	char *opcode = NULL, *s = " \n\t";

	instruction_t list[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	head = malloc(sizeof(stack_t));
	if (!head)
	{
		free_data_t(data);
		exit(EXIT_FAILURE);
	}
	while(fgets(data->line_buffer, 1024, data->file))
	{
		opcode = strtok(data->line_buffer, s);
		if (opcode)
		{
			if (strcmp("push", opcode) == 0)
				push(head, data->line++, strtok(NULL, s));
			else
				for (i = 0; list[i].opcode; i++)
					if (strcmp(opcode, list[i].opcode) == 0)
					{
					list[i].f(head, data->line++);
					break;
					}
		}
		if (list[i].opcode == NULL || status == 1)
		{
			free_stack(*head);
			free(head);
			if (!list[i].opcode)
				fprintf(stderr, "L%d: unknown instruction %s\n", data->line, opcode);
			free_data_t(data);
			exit(EXIT_FAILURE);
		}
		else
			data->line++;
	}
	free_stack(*head);
	free(head);
}
