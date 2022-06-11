/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:31:26 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/11 18:30:27 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(char **args, t_data *var)
{
	var->n_philos = ft_atol(args[1]);
	var->t_die = ft_atol(args[2]);
	var->t_eat = ft_atol(args[3]);
	var->t_sleep = ft_atol(args[4]);
	var->n_meals = 0;
	if (args[5])
		var->n_meals = ft_atol(args[5]);
	var->ph_tab = malloc(sizeof(t_philo) * var->n_philos);
	if (!var->ph_tab)
		return ;
	var->pid_tab = malloc(sizeof(int) * var->n_philos);
	if (!var->pid_tab)
		return ;
}

void	init_sem(t_data *var)
{
	sem_unlink("forks");
	sem_unlink("logs");
	var->fk_tab = sem_open("forks", O_CREAT, S_IRWXU, var->n_philos);
	var->logs = sem_open("logs", O_CREAT, S_IRWXU, 1);
}

void	init_philos(t_data *var)
{
	int	i;

	i = -1;
	while (++i < var->n_philos)
	{
		var->ph_tab[i].id = i;
		var->ph_tab[i].l_fork = i;
		var->ph_tab[i].r_fork = (i + 1) % var->n_philos;
		var->ph_tab[i].infos = var;
	}
	init_sem(var);
}

void	*check_death(void *args)
{
	t_philo	*philos;
	t_data	*var;

	philos = (t_philo *)args;
	var = philos->infos;
	while (1)
	{
		if ((exec_time() - philos->t_last_meal) > var->t_die)
		{
			sem_wait(var->logs);
			printf("%ld %d died\n", exec_time() - var->start_time, \
					philos->id + 1);
			exit(1);
		}
		usleep(50);
	}
	return (NULL);
}
