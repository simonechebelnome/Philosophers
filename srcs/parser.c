#include "../includes/philo.h"

int parse_argument(int args_count, char **args, t_table *table)
{
	int i;
	
	i = 0;
    table->philo_num = ft_atoi(args[1]);
    if(table->philo_num < 0 || !table->philo_num)
        return 1;
	while(i < table->philo_num)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	//table->forks[i] = '\0';
    table->die_time = ft_atoi(args[2]);
    if(table->die_time < 0 || !table->die_time)
        return 2;
    table->eat_time = ft_atoi(args[3]);
    if(table->eat_time < 0 || !table->eat_time)
        return 3;
    table->sleep_time = ft_atoi(args[4]);
    if(table->sleep_time < 0 || !table->sleep_time)
        return 4;
    if(args_count > 5)
	{
    	table->eat_count = ft_atoi(args[5]);
    	if(table->eat_count < 0 || !table->eat_count)
        	return 5;
	}

	// -- WARNING: SOME USELESS DEBUG SHIT --
	if(args[6] && !strcmp(args[6], "--debug"))
		debugghino_parserino(table);

    return 0;
}