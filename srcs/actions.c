#include "../includes/philo.h"

int *eat_time(t_table *table)
{
    pthread_mutex_lock(&table->forks[table->philosophers->right_fork]);
    printf(RED"Il filosofo ha afferrato la forchetta destra\n");
    pthread_mutex_unlock(&table->forks[table->philosophers->right_fork]);
    pthread_mutex_lock(&table->forks[table->philosophers->left_fork]);
    printf(RED"Il filosofo ha afferratto la forchetta sinistra\n");
    pthread_mutex_unlock(&table->forks[table->philosophers->left_fork]);
    usleep(table->eat_time);
    printf(GREEN"Il filosofo ha finito di mangiare\n");
    return 0;
}