#include "../includes/philo.h"

void exit_and_destroy(t_table *table, char *message)
{
	int i;

	i = 0;
	while(i < table->philo_num)
	{
		printf(PURPLE"Distruggo il mutex sulla forchetta %d\n", i + 1);
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
    printf(RED"\n%s\n", message);
    printf(GREEN"EXITING PROGRAM...\n\n");
    exit(0);
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


void    debugghino_parserino(t_table *table)
{
    printf(GREEN"\n// DEBUGGING START\n\n");
    printf(WHITE"Numero Filosofi: %d\n", table->philo_num);
	printf("Tempo Morte: %d\n", table->die_time);
	printf("Tempo per Mangiare: %d\n", table->eat_time);
	printf("Tempo per dormire: %d\n", table->sleep_time);
	printf(GREEN"\n// DEBUGGING END\n\n");
}