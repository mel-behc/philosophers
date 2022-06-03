#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

// typedef struct t_philos
// {
// ~~~
// }   t_philos;

typedef struct t_data
{
    int nPhilosophers;
    int philosohers;
    int tDie;
    int tEat;
    int tSleep;
    int i;
}   t_data;

int	ft_atoi(const char *str);
int ft_isdigit(int c);
void    ft_putstr(char *s);
long long	ft_time(void);


#endif