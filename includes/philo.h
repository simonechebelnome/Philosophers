#ifndef PHILO_H
#define PHILO_H

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

#define PARSE_ERROR		"PARSE ERROR!"
#define	INVALID_ARGS	"INVALID ARGUMENTS!"
#define THREAD			"ERROR OCCURED WHEN CREATING THREADS"
#define	DEATH			"OH NO! SOMEONE JUST DIED :("
#define SUCCESS			"YAAAAAYY! YOU MADE IT!"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct	s_philo
{
	int				id;
	int				is_dead;
	int				right_fork;
	int				left_fork;
	struct s_table	*table;
	pthread_t		thread_id;
}				t_philo;

typedef struct	s_table
{
	pthread_mutex_t forks[20];
	t_philo			philosophers[20];
    int				philo_num;
	int 			count;
    int				die_time;
	int				sleep_time;
	int				eat_time;
	int				eat_count;
}				t_table;

/* MAIN CODE */
void	*routine(void *philosopher_tmp);
int		thread_start(t_table *table);

/* PARSING */
int		parse_argument(int argc, char **args, t_table *table);
int		fill_osophers(t_table *table);

/* UTILS */
void 	exit_and_destroy(t_table *table, char *message);
int		ft_atoi(const char *str);
void	print_header();

/* DEBUG */
void    debugghino_parserino(t_table *table);

/* ACTIONS */
int *eat_time(t_table *table);
#endif
