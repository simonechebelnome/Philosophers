/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:18 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 15:12:19 by smenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	*eat_time(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->forks[philo->left_fork]);
	print_message(table, "has taken a fork", philo->id);
	pthread_mutex_lock(&table->forks[philo->right_fork]);
	print_message(table, "has taken a fork", philo->id);
	pthread_mutex_lock(&table->eat_lock);
	print_message(table, YELLOW"is eating", philo->id);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&table->eat_lock);
	my_usleep(table->eat_time, table);
	(philo->have_eaten)++;
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
	return (0);
}
