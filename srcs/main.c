#include "../includes/philo.h"

int	main(int args_count, char **args)
{
	t_table	table;

	print_header();
	if (args_count < 5 || args_count > 6)
		return_error(INVALID_ARGS);
	if (parse_argument(args_count, args, &table))
		return_error(PARSE_ERROR);
	if (thread_start(&table))
		return_error(THREAD);
	return (0);
}
