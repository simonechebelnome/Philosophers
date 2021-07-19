#include "../includes/philo.h"

void *routine(void *philosopher_tmp)
{	
	t_philo	*philo = (t_philo *)philosopher_tmp;
	t_table	*table; //This must be in someway initialized
	table = philo->table;
	//printf(YELLOW"Inizializzazione Thread [FILOSOFO %d]\n", philo->id);

	if (philo->id % 2)
		usleep(15000);
	while(table->is_dead != 1) //This technically is the main part of the code
	{
		eat_time(philo);
		if(table->all_ate)
			break;
		print_message(table, YELLOW"is sleeping", philo->id);
		my_usleep(table->sleep_time, table);
		print_message(table, YELLOW"is thinking", philo->id);
	}
	return 0;
}

int	thread_start(t_table *table)
{
	t_philo *philo = table->philosophers;
	int i = 0;

	while (i < table->philo_num)   
	{
		if(pthread_create(&(philo[i].thread_id), NULL, routine, &(philo[i])) != 0)
			return 1; 
		philo[i].last_meal = get_time();
		i++;
	}
	check_death(table, table->philosophers);
	exit_and_destroy(table, philo);
	return(0);
}

void	check_death(t_table *table, t_philo *philo)
{
	int i;

	while(!(table->all_ate))
	{
		i = -1;
		while(++i < table->philo_num && table->is_dead != 1)
		{
			pthread_mutex_lock(&table->eat_lock);
			if((get_time() - philo[i].last_meal) > table->die_time)
			{
				print_message(table, RED"died", philo[i].id);
				table->is_dead = 1;
			}
			pthread_mutex_unlock(&table->eat_lock);
		}
		if(table->is_dead)
			break;
		i = 0;
		while (table->no_ate != -1 && i < table->philo_num && philo[i].have_eaten >= table->no_ate)
			i++;
		if(i == table->philo_num)
			table->all_ate = 1;
	}
}