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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct	s_table
{
    int		philo_num;
    int		die_time;
	int		sleep_time;
	int		eat_time;
	int		eat_count;
	int		*forks;
}				t_table;

int parse_argument(int argc, char **args, t_table *table);

#endif
