#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct  s_philo
{
    pthread_mutex_t lock;
    long i;
}               t_philo;

#endif
