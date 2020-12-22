#include "monty.h"

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

	return (data);
}

void free_data_t(data_t *data)
{
	free(data->line_buffer);
	fclose(data->file);
	free(data);
}
