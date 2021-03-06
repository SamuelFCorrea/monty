#include "monty.h"

int status = EXIT_SUCCESS;

/**
 * main - initialize the variables and free the memory
 * @ac: argument count
 * @av: argumets
 *
 * Return: on succes 0 othewise 1
 */

int main(int ac, char **av)
{
	FILE *file;
	unsigned int line = 1;
	size_t line_len = 0;
	stack_t *stack = NULL;
	char *buf = NULL, *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &line_len, file) != -1 && status == EXIT_SUCCESS)
	{
		opcode = strtok(buf, " \t\n");
		if (!opcode || *buf == '#')
		{
			line++;
			continue;
		}
		argument.arg = strtok(NULL, " \t\n");
		opcode_run(&stack, opcode, line++);
	}

	free(buf);
	fclose(file);
	free_stack(stack);
	exit(status);
}

/**
 * opcode_run - find and run the correct fuction
 * @head: stack head
 * @opcode: opcode
 * @line: line number
 *
 * Return: none
 */

void opcode_run(stack_t **head, char *opcode, unsigned int line)
{
	int i;
	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	for (i = 0; ins[i].opcode; i++)
		if (strcmp(ins[i].opcode, opcode) == 0)
			break;
	if (ins[i].opcode)
		ins[i].f(head, line);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		status = EXIT_FAILURE;
	}
}
