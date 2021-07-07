#include "../includes/philo.h"

int	main(int args_count, char **args)
{
	t_table	table;

	if (args_count < 5 || args_count > 7) // Change 7 to 6 when you finish
		exit_message(INVALID_ARGS);
	if(parse_argument(args_count, args, &table))
		exit_message(PARSE_ERROR);
	if(thread_start(&table))
		exit_message(THREAD);
	return 0;
}