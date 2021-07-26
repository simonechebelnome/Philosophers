/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:50 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 15:15:50 by smenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	exit_and_destroy(t_table *table)
{
	int	i;
	int	state;

	i = 0;
	while (i < table->philo_num)
	{
		waitpid(-1, &state, 0);
		if (state != 0)
		{
			i = -1;
			while (++i < table->philo_num)
				kill(table->philosophers[i].process_id, 15);
			break ;
		}
		i++;
	}
	sem_close(table->forks);
	sem_close(table->write);
	sem_close(table->eat_lock);
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/eat_lock");
}

int	return_error(char *message)
{
	printf("%s\n", message);
	return (1);
}

void	print_header(void)
{
	printf(BLUE"\n");
	printf(" ___ ___        _   _ _                 _       \n");
	printf("| | |_  |   ___| |_|_| |___ ___ ___ ___| |_ ___ ___ ___ \n");
	printf("|_  |  _|  | . |   | | | . |_ -| . | . |   | -_|  _|_ -|\n");
	printf("  |_|___|  |  _|_|_|_|_|___|___|___|  _|_|_|___|_| |___|\n");
	printf("           |_|                     |_|                  \n");
	printf(WHITE"						made by"RED" smenna\n\n");
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str
			== '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	if (res >= 9223372036854775808ULL && negative == 1)
		return (-1);
	return (res * negative);
}

void	print_message(t_table *table, char *message, int id)
{
	sem_wait(table->write);
	if (table->is_dead != 1)
	{
		printf(WHITE"["GREEN"%lli"WHITE"]", get_time() - table->start_time);
		printf(RED" %d ", id + 1);
		printf(GREEN"%s\n", message);
	}
	sem_post(table->write);
}
