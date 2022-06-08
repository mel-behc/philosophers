#include "philo.h"

void initArgs(char **args, t_data *var)
{
	var->nPhilos = ft_atol(args[1]);
	var->tDie = ft_atol(args[2]);
	var->tEat = ft_atol(args[3]);
	var->tSleep = ft_atol(args[4]);
	var->nMeals = 0;
	if (args[5])
		var->nMeals = ft_atol(args[5]);
	var->phTab = malloc(sizeof(t_philo) * var->nPhilos);
	if (!var->phTab)
		return ;
}

void initPhilos(t_data *var)
{
	int i;

	i = -1;
	while (++i < var->nPhilos)
	{
		var->phTab[i].id = i;
		var->phTab[i].lFork = i;
		var->phTab[i].rFork = (i + 1) % var->nPhilos;
		var->phTab[i].infos = var;
	}
	initSem(var);
}

void initSem(t_data *var)
{
	sem_unlink("forks");
	sem_unlink("logs");
	var->fkTab = sem_open("forks", O_CREAT, S_IRWXU, var->nPhilos);
	var->logs = sem_open("logs", O_CREAT, S_IRWXU, 1);
}

void *checkDeath(void *args)
{
	t_philo *philos;
	t_data	*var;

	philos = (t_philo *)args;
	var = philos->infos;
	while (1)
	{
		if ((execTime() - philos->tLastMeal) > var->tDie)
		{
			sem_wait(var->logs);
			printf("%ld %d died\n", (execTime() - var->startTime), (philos->id + 1));
			exit(1);
		}
		usleep(50);
	}
	return (NULL);
}