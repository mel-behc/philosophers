/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:30:54 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/08 03:30:55 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void printLogs(t_data *var, char *log, int philoId)
{
	pthread_mutex_lock(&var->logs);
	printf("%ld %d %s\n", (execTime() - var->startTime), philoId, log);
	pthread_mutex_unlock(&var->logs);
	
}

static void *routine(void *param)
{
	t_philo *philo;
	t_data	*var;

	philo = (t_philo *)param;
	var = philo->infos;
	var->lastVar = 0;
	if (philo->id % 2)
		ft_usleep(100);
	while (1)
	{
		pthread_mutex_lock(&var->fkTab[philo->lFork]);
		printLogs(var, "has taken a fork", philo->id + 1);
		pthread_mutex_lock(&var->fkTab[philo->rFork]);
		printLogs(var, "has taken a fork", philo->id + 1);
		printLogs(var, "is eating", philo->id + 1);
		philo->tLastMeal = execTime();
		ft_usleep(var->tEat);
		pthread_mutex_unlock(&var->fkTab[philo->lFork]);
		pthread_mutex_unlock(&var->fkTab[philo->rFork]);
		var->lastVar++;
		printLogs(var, "is sleeping", philo->id + 1);
		ft_usleep(var->tSleep);
		printLogs(var, "is thinking", philo->id + 1);
	}
}


void threadCreat(t_data *var)
{
	int i;

	i = -1;
	var->startTime = execTime();
	while (++i <  var->nPhilos)
	{
		var->phTab[i].tLastMeal = execTime();
		pthread_create(&(var->phTab[i].thread), NULL, &routine, &var->phTab[i]);
	}
	checkDeath(var);
}

int	main(int ac, char **av)
{
	t_data	var;

	if (ac == 1)
		return 0;
	var.args = ac - 1;
	if (!argsChecker(&av[1], var.args))
		ft_putstr("Wrong args\n");
	initArgs(av, &var);
	initPhilos(&var);
	threadCreat(&var);
	freeAlloc(&var, 1);
	return (0);
}
