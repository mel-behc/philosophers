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
// 
// }   t_philos;

typedef struct t_data
{
    int nPhilosophers;
    int tDie;
    int tEat;
    int tSleep;
    int nOfmeals;
    long long time;
}   t_data;

long    ft_atol(const char *str);
int     ft_isdigit(int c);
void    ft_putstr(char *s);
int     argsChecker(char **str, int nOfargs);
long long	ft_time(void);



#endif