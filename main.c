#include "monty.h"


int main(int ac, char **av)
{
	data_t *data = NULL;
	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(av[1], F_OK | R_OK))
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	data = init(av[1]);
	
	s_and_e(data);


	free_data_t(data);

	return (EXIT_SUCCESS);
}
