#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>



typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	long				tLastMeal;
	int					lFork;
	int					rFork;
	struct s_data		*infos;
}	t_philo;

typedef struct s_data
{
	int				args;
	int				nPhilos;
	int				tDie;
	int				tEat;
	int				tSleep;
	int				nMeals;
	int				lastVar;
	long		    startTime;
	sem_t 			*fkTab;
	sem_t 			*logs;
	int				*pidTab;
	struct s_philo	*phTab;
}   t_data;



long    ft_atol(const char *str);
void    ft_putstr(char *s);
int		argsChecker(char **str, int nOfargs);
long    execTime(void);
void	ft_usleep(int time);
void	initArgs(char **args, t_data *var);
void	initPhilos(t_data *var);
void	initSem(t_data *var);
void	*checkDeath(void *args);
void 	threadCreat(t_data *var, int lastArg);
void	*routine_1(t_philo *philo);
void	*routine_2(t_philo *philo);

#endif