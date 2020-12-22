#include "monty.h"

/**
 * init - initialize the struct with important data
 * @file_name: name of the file with the monty code
 *
 * Return: pointer to a structure with the data set
 */

data_t *init(char *file_name)
{
	char *line = NULL;
	data_t *data = NULL;

	line = malloc(1024 * sizeof(char));
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	data = malloc(sizeof(data_t));
	if (!data)
	{
		free(line);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	data->line = 1;
	data->line_buffer = line;
	data->file_name = file_name;
	data->file = fopen(file_name, "r");
	status = 0;

	return (data);
}

/**
 * free_data_t - free the data struct
 * @data: struct to free
 *
 * Return: none
 */

void free_data_t(data_t *data)
{
	free(data->line_buffer);
	fclose(data->file);
	free(data);
}
