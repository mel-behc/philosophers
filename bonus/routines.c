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

static void print_logs(t_data *var, char *log, int philo_id)
{
	sem_wait(var->logs);
	printf("%ld %d %s\n", (exec_time() - var->start_time), philo_id, log);
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
		sem_wait(var->fk_tab);
		print_logs(var, "has taken a fork", philo->id + 1);
		sem_wait(var->fk_tab);
		print_logs(var, "has taken a fork", philo->id + 1);
		print_logs(var, "is eating", philo->id + 1);
		philo->t_last_meal = exec_time();
		ft_usleep(var->t_eat);
		sem_post(var->fk_tab);
		sem_post(var->fk_tab);
		var->last_var++;
		print_logs(var, "is sleeping", philo->id + 1);
		ft_usleep(var->t_sleep);
		print_logs(var, "is thinking", philo->id + 1);
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
	while (++i < var->n_meals)
	{
		sem_wait(var->fk_tab);
		print_logs(var, "has taken a fork", philo->id + 1);
		sem_wait(var->fk_tab);
		print_logs(var, "has taken a fork", philo->id + 1);
		print_logs(var, "is eating", philo->id + 1);
		philo->t_last_meal = exec_time();
		ft_usleep(var->t_eat);
		sem_post(var->fk_tab);
		sem_post(var->fk_tab);
		var->last_var++;
		print_logs(var, "is sleeping", philo->id + 1);
		ft_usleep(var->t_sleep);
		print_logs(var, "is thinking", philo->id + 1);
	}
    return (NULL);
}
