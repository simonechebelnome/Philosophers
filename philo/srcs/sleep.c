/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:27 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 15:12:28 by smenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	long long		my_time;
	struct timeval	t;

	gettimeofday(&t, NULL);
	my_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (my_time);
}

void	my_usleep(int time, t_table *table)
{
	long long	end_time;

	end_time = get_time() + time;
	while (get_time() < end_time && !table->is_dead)
		usleep(time);
}
