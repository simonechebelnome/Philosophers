/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:12 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 15:37:27 by smenna           ###   ########.fr       */
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

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_philo
{
	int				id;
	int				have_eaten;
	long long		last_meal;
	struct s_table	*table;
	pthread_t		check;
	pid_t			process_id;
}				t_philo;

typedef struct s_table
{
	sem_t			*forks;
	sem_t			*write;
	sem_t			*eat_lock;
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
void		routine(void *philosopher_tmp);
int			thread_start(t_table *table);
void		*check_death(void *philo_tmp);

/* PARSING */
int			parse_argument(int argc, char **args, t_table *table);
int			fill_osophers(t_table *table);
int			init_sem(t_table *table);

/* UTILS */
void		exit_and_destroy(t_table *table);
int			ft_atoi(const char *str);
void		print_header(void);
void		my_usleep(int time, t_table *table);
void		print_message(t_table *table, char *message, int id);
long long	get_time(void);
int			return_error(char *message);

/* ACTIONS */
void		eat_time(t_philo *philo);

#endif
