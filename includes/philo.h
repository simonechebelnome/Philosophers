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

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct	s_philo
{
	int				th_count;
	int				is_dead;
	struct s_table	*table;
	pthread_t		id;
}				t_philo;

typedef struct	s_table
{
	pthread_mutex_t lock;
	t_philo			philosophers[20];
    int				philo_num;
	int 			count;
    int				die_time;
	int				sleep_time;
	int				eat_time;
	int				eat_count;
	int				*forks; //THIS CAN'T ACTUALLY BE AN INT ARRAY
}				t_table;

/* MAIN CODE */
void	*routine(void *philosopher_tmp);
int		thread_start(t_table *table);

/* PARSING */
int		parse_argument(int argc, char **args, t_table *table);

/* UTILS */
void	exit_message(char *message);
int		ft_atoi(const char *str);

/* DEBUG */
void    debugghino_parserino(t_table *table);

#endif
