/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:31:45 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/08 03:31:47 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void printLogs(t_data *var, char *log, int philoId)
{
	sem_wait(var->logs);
	printf("%ld %d %s\n", (execTime() - var->startTime), philoId, log);
	sem_post(var->logs);
	
}

void *routine_1(t_philo *philo)
{
	t_data	*var;

	var = philo->infos;
	if (philo->id % 2)
		ft_usleep(100);
	while (1)
	{
		sem_wait(var->fkTab);
		printLogs(var, "has taken a fork", philo->id + 1);
		sem_wait(var->fkTab);
		printLogs(var, "has taken a fork", philo->id + 1);
		printLogs(var, "is eating", philo->id + 1);
		philo->tLastMeal = execTime();
		ft_usleep(var->tEat);
		sem_post(var->fkTab);
		sem_post(var->fkTab);
		var->lastVar++;
		printLogs(var, "is sleeping", philo->id + 1);
		ft_usleep(var->tSleep);
		printLogs(var, "is thinking", philo->id + 1);
	}
    return (NULL);
}

void *routine_2(t_philo *philo)
{
	t_data	*var;
    int     i;

	var = philo->infos;
	if (philo->id % 2)
		ft_usleep(100);
    i = -1;
    // printf("***********%d***********\n", var->lastVar);
	while (++i < var->nMeals)
	{
		sem_wait(var->fkTab);
		printLogs(var, "has taken a fork", philo->id + 1);
		sem_wait(var->fkTab);
		printLogs(var, "has taken a fork", philo->id + 1);
		printLogs(var, "is eating", philo->id + 1);
		philo->tLastMeal = execTime();
		ft_usleep(var->tEat);
		sem_post(var->fkTab);
		sem_post(var->fkTab);
		var->lastVar++;
		printLogs(var, "is sleeping", philo->id + 1);
		ft_usleep(var->tSleep);
		printLogs(var, "is thinking", philo->id + 1);
	}
    return (NULL);
}
