#include "../includes/philo.h"

int	main(int args_count, char **args)
{
	t_table	table;

	print_header();
	if (args_count < 5 || args_count > 7) // Change 7 to 6 when you finish
		exit_and_destroy(&table, INVALID_ARGS);
	if(parse_argument(args_count, args, &table))
		exit_and_destroy(&table, PARSE_ERROR);
	if(thread_start(&table))
		exit_and_destroy(&table, THREAD);
	exit_and_destroy(&table, SUCCESS); // I just need this to destroy mutex, it will probably be deleted after
	return 0;
}