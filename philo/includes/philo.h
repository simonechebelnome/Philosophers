/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:04 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 15:12:05 by smenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define PARSE_ERROR	"PARSE ERROR!"
# define INVALID_ARGS	"INVALID ARGUMENTS!"
# define THREAD			"ERROR OCCURED WHEN CREATING THREADS"
# define SUCCESS		"I'M EXITING THE PROGRAM"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				right_fork;
	int				have_eaten;
	int				left_fork;
	long long		last_meal;
	struct s_table	*table;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_table
{
	pthread_mutex_t	forks[250];
	pthread_mutex_t	write;
	pthread_mutex_t	eat_lock;
	t_philo			philosophers[250];
	long long		start_time;
	int				is_dead;		
	int				all_ate;
	int				no_ate;
	int				philo_num;
	int				count;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	int				eat_count;
}				t_table;

/* MAIN CODE */
void		*routine(void *philosopher_tmp);
int			thread_start(t_table *table);
void		check_death(t_table *table, t_philo *philo);

/* PARSING */
int			parse_argument(int argc, char **args, t_table *table);
int			fill_osophers(t_table *table);
int			init_mutex(t_table *table);

/* UTILS */
void		exit_and_destroy(t_table *table, t_philo *philo);
int			ft_atoi(const char *str);
void		print_header(void);
void		my_usleep(int time, t_table *table);
void		print_message(t_table *table, char *message, int id);
long long	get_time(void);
int			return_error(char *message);

/* ACTIONS */
int			*eat_time(t_philo *philo);

#endif
