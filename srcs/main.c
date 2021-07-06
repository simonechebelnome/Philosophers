#include "../includes/philo.h"

int main(int args_count, char **args)
{
	t_table table;

	if (args_count < 5 || args_count > 7) // Change 7 to 6 when you finish
		exit_and_free(&table, INVALID_ARGS);
	if(parse_argument(args_count, args, &table))
		exit_and_free(&table, PARSE_ERROR);
	if(thread_start(&table))
		exit_and_free(&table, THREAD);
	free(&table);
	return 0;
}