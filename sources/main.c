#include "philo.h"

pthread_mutex_t lock;

void *routine(void *count)
{	
	pthread_mutex_lock(&lock);
	printf(YELLOW"Inizializzazione Thread %d\n", (int)count++);
	sleep(3);
	printf("Fine thread \n");
	pthread_mutex_unlock(&lock);	
	return 0;
}

int main(int args_count, char **args)
{
	if (args_count != 5)
	{
		printf(RED"Errore nel numero di argomenti!\n");
		return 1;
    }
	pthread_mutex_init(&lock, NULL);
	t_table *table = (void *)malloc(sizeof(t_table));
	parse_argument(args_count, args, table);
	int *i; //As a test for passing argument to thread

	printf(RED"Attualmente ci sono %d Filosofi e %d Forchette!\n", table->philo_num, table->philo_num);
    pthread_t th[table->philo_num];
	int count = 0;
	while (count < table->philo_num)   
	{
		i = malloc(sizeof(*i));
		*i = count;
		if(pthread_create(th + count, NULL, &routine, i) != 0)
			return 1; 
		pthread_join(th[count], NULL);
		count++;
	}
	pthread_mutex_destroy(&lock);
	return 0;
}