#include "../includes/philo.h"

int	thread_start(t_table *table)
{
	t_philo *philo = table->philosophers;
	pthread_t th[table->philo_num];
	int i = 0;

	printf(RED"Attualmente ci sono %d Filosofi e %d Forchette!\n", table->philo_num, table->philo_num);
	while (i < table->philo_num)   
	{
		philo[i].id = i + 1;
		if(pthread_create(th + i, NULL, routine, &(philo[i])) != 0)
			return 1; 
		pthread_join(th[i], NULL);
		i++;
	}
	return(0);
}

void *routine(void *philosopher_tmp)
{	
	t_philo *philo = (t_philo *)philosopher_tmp;
	t_table *table; //This must be in someway initialized
	table = philo->table;

	pthread_mutex_t lock;

	pthread_mutex_init(&lock, NULL);	
	pthread_mutex_lock(&lock);
	printf(YELLOW"Inizializzazione Thread [FILOSOFO %d]\n", philo->id);

    while(philo->is_dead != 1) //This technically is the main part of the code
    {
		//eat_time(table);
		usleep(table->eat_time); 
		usleep(table->sleep_time);
		usleep(2000); //The time to think isn't specified
    }

	printf("Fine thread\n");
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);	
	return 0;
}


