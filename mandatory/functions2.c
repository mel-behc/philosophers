/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:30:48 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/08 03:30:49 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	var->fkTab = malloc(sizeof(pthread_mutex_t) * var->nPhilos);
	if (!var->fkTab)
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
	initMutex(var);
}

void initMutex(t_data *var)
{
	int	i;

	i = -1;
	while (++i < var->nPhilos)
		pthread_mutex_init(&(var->fkTab[i]), NULL);
	pthread_mutex_init(&var->logs, NULL);
}

static int checkLastArg(t_data *var)
{
	if (!(var->lastVar >= (var->nMeals * var->nPhilos)))
		return 0;
	return 1;
}

void checkDeath(t_data *var)
{
	int i;

	while (1)
	{
		i = -1;
		while (++i < var->nPhilos)
		{
			if (var->args == 5)
				if (checkLastArg(var))
					return ;
			if ((execTime() - var->phTab[i].tLastMeal) > var->tDie)
			{
				pthread_mutex_lock(&var->logs);
				printf("%ld %d died\n", (execTime() - var->startTime), var->phTab[i].id + 1);
				return ;
			}
			usleep(50);
		}
	}
}
