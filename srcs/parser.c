#include "../includes/philo.h"

int	parse_argument(int args_count, char **args, t_table *table)
{
	table->philo_num = ft_atoi(args[1]);
	table->die_time = ft_atoi(args[2]);
	table->eat_time = ft_atoi(args[3]);
	table->sleep_time = ft_atoi(args[4]);
	table->all_ate = 0;
	table->is_dead = 0;
	if (table->die_time < 0 || !table->die_time || table->eat_time < 0
		|| !table->eat_time || table->sleep_time < 0 || !table->sleep_time
		||table->philo_num < 0 || !table->philo_num)
		return (1);
	if (args_count > 5)
	{
		table->eat_count = ft_atoi(args[5]);
		if (table->eat_count < 0 || !table->eat_count)
			return (2);
	}
	else
		table->eat_count = -1;
	if(init_mutex(table))
		return (3);
	fill_osophers(table);
	return (0);
}

int	init_mutex(t_table *table)
{
	int i;

	i = -1;
	while(++i < table->philo_num)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (1);
	}
	if (pthread_mutex_init(&table->write, NULL))
		return (2);
	if (pthread_mutex_init(&table->eat_lock, NULL))
		return (3);
	return(0);
}

int	fill_osophers(t_table *table)
{
	int	i;

	i = table->philo_num;
	while (--i >= 0)
	{
		table->philosophers[i].id = i;
		table->philosophers[i].left_fork = i;
		table->philosophers[i].right_fork = (i + 1) % table->philo_num;
		table->philosophers[i].table = table;
		table->philosophers[i].last_meal = 0;
		table->philosophers[i].have_eaten = 0;
	}
	return (0);
}
