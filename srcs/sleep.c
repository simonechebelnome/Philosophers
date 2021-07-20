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
	while (get_time() < end_time && table->is_dead != 1)
		usleep(time);
}
