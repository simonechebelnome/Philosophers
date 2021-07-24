/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:44 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 16:46:20 by smenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine(void *philosopher_tmp)
{	
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)philosopher_tmp;
	table = philo->table;
	philo->last_meal = get_time();
	pthread_create(&(philo->check), NULL, check_death, philosopher_tmp);
	if (philo->id % 2)
		usleep(15000);
	while (!table->is_dead)
	{
		eat_time(philo);
		if (philo->have_eaten >= table->eat_count && table->eat_count != -1)
			break ;
		print_message(table, YELLOW"is sleeping", philo->id);
		my_usleep(table->sleep_time, table);
		print_message(table, YELLOW"is thinking", philo->id);
	}
	pthread_join(philo->check, NULL);
	if (table->is_dead)
		exit(1);
	exit(0);
}

int	thread_start(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = table->philosophers;
	table->start_time = get_time();
	while (++i < table->philo_num)
	{
		philo[i].process_id = fork();
		if (philo[i].process_id < 0)
			return (1);
		if (philo[i].process_id == 0)
			routine(&(philo[i]));
		usleep(100);
	}
	exit_and_destroy(table);
	return (0);
}

void	*check_death(void *philo_tmp)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)philo_tmp;
	table = philo->table;
	while (1)
	{
		sem_wait(table->eat_lock);
		if ((get_time() - philo->last_meal) > table->die_time)
		{
			print_message(table, RED"died", philo->id);
			table->is_dead = 1;
			sem_wait(table->write);
			exit(1);
		}
		sem_post(table->eat_lock);
		if (table->is_dead)
			break ;
		usleep(1000);
		if (philo->have_eaten >= table->eat_count && table->eat_count != -1)
			break ;
	}
	return (NULL);
}
