/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:35 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 15:30:52 by smenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat_time(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	sem_wait(table->forks);
	print_message(table, "has taken a fork", philo->id);
	sem_wait(table->forks);
	print_message(table, "has taken a fork", philo->id);
	sem_wait(table->eat_lock);
	print_message(table, YELLOW"is eating", philo->id);
	philo->last_meal = get_time();
	sem_post(table->eat_lock);
	my_usleep(table->eat_time, table);
	(philo->have_eaten)++;
	sem_post(table->forks);
	sem_post(table->forks);
}
