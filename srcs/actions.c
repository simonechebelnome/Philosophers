#include "../includes/philo.h"

int	*eat_time(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->forks[table->philosophers->left_fork]);
	print_message(table, "has taken a fork", philo->id);
	pthread_mutex_lock(&table->forks[table->philosophers->right_fork]);
	print_message(table, "has taken a fork", philo->id);
	pthread_mutex_lock(&table->eat_lock);
	print_message(table, YELLOW"is eating", philo->id);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&table->eat_lock);
	my_usleep(table->eat_time, table);
	(philo->have_eaten)++;
	pthread_mutex_unlock(&table->forks[table->philosophers->right_fork]);
	pthread_mutex_unlock(&table->forks[table->philosophers->left_fork]);
	return (0);
}
