#include "philo.h"

pthread_mutex_t lock;

void *routine()
{
	pthread_mutex_lock(&lock);
    printf("Inizializzazione Thread\n");
    sleep(3);
    printf("Fine thread \n");
	pthread_mutex_unlock(&lock);	
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Errore");
        return 1;
    }
    pthread_mutex_init(&lock, NULL);
	int thread_num = atoi(argv[1]);
    pthread_t th[thread_num];
    int count = 0;
    while (count < thread_num)   
	{
        if(pthread_create(th + count, NULL, &routine, NULL) != 0) // Creates the thread
            return 1; 
        pthread_join(th[count], NULL); // Waits for the thread to execute
        count++;
	}
	pthread_mutex_destroy(&lock);
    return 0;
}