#include "../includes/philo.h"

int	parse_argument(int args_count, char **args, t_table *table)
{
	int	i;

	table->philo_num = ft_atoi(args[1]);
	if (table->philo_num < 0 || !table->philo_num)
		return (1);
	i = -1;
	while (++i < table->philo_num)
		pthread_mutex_init(&table->forks[i], NULL);
	table->die_time = ft_atoi(args[2]);
	table->eat_time = ft_atoi(args[3]);
	table->sleep_time = ft_atoi(args[4]);
	if (table->die_time < 0 || !table->die_time || table->eat_time < 0
		|| !table->eat_time || table->sleep_time < 0 || !table->sleep_time)
		return (2);
	if (args_count > 5)
	{
		table->eat_count = ft_atoi(args[5]);
		if (table->eat_count < 0 || !table->eat_count)
			return (3);
	}
	else
		table->eat_count = -1;
	fill_osophers(table);
	return (0);
}

int	fill_osophers(t_table *table)
{
	int	i;

	i = table->philo_num;
	while (--i >= 0)
	{
		table->philosophers[i].id = i;
		table->philosophers[i].right_fork = i;
		table->philosophers[i].left_fork = (i + 1) % table->philo_num;
		table->philosophers[i].table = table;
	}
	return (0);
}
