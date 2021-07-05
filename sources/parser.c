#include "philo.h"

int parse_argument(int args_count, char **args, t_table *table)
{
	int i;
	
	i = 0;
    table->philo_num = atoi(args[1]);
    if(table->philo_num < 0)
        return 1;
	table->forks = (int *)malloc(sizeof(int) * table->philo_num + 1);
	while(i < table->philo_num)
	{
		table->forks[i] = i + 1;
		i++;
	}
	table->forks[i] = 0;
    table->die_time = atoi(args[2]);
    if(table->die_time < 0)
        return 2;
    table->eat_time = atoi(args[3]);
    if(table->eat_time < 0)
        return 3;
    table->sleep_time = atoi(args[4]);
    if(table->sleep_time < 0)
        return 4;
    if(args_count > 5)
	{
    	table->eat_count = atoi(args[5]);
    	if(table->eat_count < 0)
        	return 5;
	}

	// -- WARNING: SOME USELESS DEBUG SHIT --
	printf(GREEN"Numero Filosofi: %d\n", table->philo_num);
	printf("Tempo Morte: %d\n", table->die_time);
	printf("Tempo per Mangiare: %d\n", table->eat_time);
	printf("Tempo per dormire: %d\n", table->sleep_time);
	i = 0;
	while(table->forks[i] != 0)
	{
		printf("Forchetta Numero: %d\n", table->forks[i]);
		i++;
	} 
	printf("-- FINE DEBUG ARGOMENTI --\n\n");

    return 0;
}