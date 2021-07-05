#include "../includes/philo.h"

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
	t_table *table = (void *)malloc(sizeof(t_table));
	int *i; //As a test for passing argument to thread
	int count = 0;

	pthread_mutex_init(&lock, NULL);
	if (args_count < 5 || args_count > 7) // Change 7 to 6 when you finish
		exit_and_free(table, INVALID_ARGS);
	if(parse_argument(args_count, args, table) != 0)
		exit_and_free(table, PARSE_ERROR);

	pthread_t th[table->philo_num];
	printf(RED"Attualmente ci sono %d Filosofi e %d Forchette!\n", table->philo_num, table->philo_num);
	while (count < table->philo_num)   
	{
		i = malloc(sizeof(*i));
		*i = count;
		if(pthread_create(th + count, NULL, &routine, i) != 0)
			return 1; 
		pthread_join(th[count], NULL);
		count++;
	}
	free(table);
	pthread_mutex_destroy(&lock);
	return 0;
}