/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:42 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 15:14:48 by smenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parse_argument(int args_count, char **args, t_table *table)
{
	table->philo_num = ft_atoi(args[1]);
	table->die_time = ft_atoi(args[2]);
	table->eat_time = ft_atoi(args[3]);
	table->sleep_time = ft_atoi(args[4]);
	table->is_dead = 0;
	if (table->die_time < 0 || !table->die_time || table->eat_time < 0
		|| !table->eat_time || table->sleep_time < 0 || !table->sleep_time
		||table->philo_num < 0 || !table->philo_num)
		return (1);
	if (args_count > 5)
	{
		table->eat_count = ft_atoi(args[5]);
		if (table->eat_count <= 0 || !table->eat_count)
			return (2);
	}
	else
		table->eat_count = -1;
	if (table->eat_count == 1)
		table->eat_count++;
	if (init_sem(table))
		return (3);
	fill_osophers(table);
	return (0);
}

int	init_sem(t_table *table)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/eat_lock");
	table->forks = sem_open("/forks", O_CREAT, table->philo_num);
	table->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	table->eat_lock = sem_open("/eat_lock", O_CREAT, S_IRWXU, 1);
	return (0);
}

int	fill_osophers(t_table *table)
{
	int	i;

	i = table->philo_num;
	while (--i >= 0)
	{
		table->philosophers[i].id = i;
		table->philosophers[i].table = table;
		table->philosophers[i].last_meal = 0;
		table->philosophers[i].have_eaten = 0;
	}
	return (0);
}
