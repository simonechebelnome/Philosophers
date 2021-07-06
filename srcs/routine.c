#include "../includes/philo.h"

void *routine(void *philosopher_tmp)
{	
	t_philo *philo = (t_philo *)philosopher_tmp;
	t_table *table; //This must be in someway initialized
	table = philo->table;

	pthread_mutex_t lock;
	pthread_mutex_init(&lock, NULL);	
	pthread_mutex_lock(&lock);
	printf(YELLOW"Inizializzazione Thread [FILOSOFO %d]\n", philo->th_count);

    while(philo->is_dead != 1) //This technically is the main part of the code
    {
		//eat_time(table);
		usleep(table->eat_time); 
		usleep(table->sleep_time);
		//usleep(2000); //The time to think isn't specified
		if(table->eat_time + table->sleep_time > table->die_time)
			philo->is_dead = 1;
    }

	printf("Fine thread\n");
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);	
	return 0;
}

int	thread_start(t_table *table)
{
	t_philo *philo = table->philosophers;
	memcpy(&philo->table, &table, sizeof(table));
	int i = 0;

	printf(RED"Attualmente ci sono %d Filosofi e %d Forchette!\n", table->philo_num, table->philo_num);
	while (i < table->philo_num)   
	{
		philo[i].th_count = i + 1;
		if(pthread_create(&(philo[i].id), NULL, routine, &(philo[i])) != 0)
			return 1; 
		pthread_join(philo[i].id, NULL);
		i++;
	}
	return(0);
}
