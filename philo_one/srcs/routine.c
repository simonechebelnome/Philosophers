#include "../includes/philo.h"

void	*routine(void *philosopher_tmp)
{	
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)philosopher_tmp;
	table = philo->table;
	if (philo->id % 2)
		usleep(15000);
	while (!table->is_dead)
	{
		eat_time(philo);
		if (table->all_ate)
			break ;
		print_message(table, YELLOW"is sleeping", philo->id);
		my_usleep(table->sleep_time, table);
		print_message(table, YELLOW"is thinking", philo->id);
	}
	return (0);
}

int	thread_start(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = table->philosophers;
	table->start_time = get_time();
	while (i < table->philo_num)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, routine, &(philo[i])))
			return (1);
		philo[i].last_meal = get_time();
		i++;
	}
	check_death(table, table->philosophers);
	exit_and_destroy(table, philo);
	return (0);
}

void	check_death(t_table *table, t_philo *philo)
{
	int	i;

	while (!(table->all_ate))
	{
		i = -1;
		while (++i < table->philo_num && !(table->is_dead))
		{
			pthread_mutex_lock(&table->eat_lock);
			if ((get_time() - philo[i].last_meal) > table->die_time)
			{
				print_message(table, RED"died", philo[i].id);
				table->is_dead = 1;
			}
			pthread_mutex_unlock(&table->eat_lock);
			usleep(100);
		}
		if (table->is_dead)
			break ;
		i = 0;
		while (table->eat_count != -1 && i < table->philo_num
			&& philo[i].have_eaten >= table->eat_count)
			i++;
		if (i == table->philo_num)
			table->all_ate = 1;
	}
}
