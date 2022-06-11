/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:30:48 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/11 18:39:02 by melbehchach      ###   ########.fr       */
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
	var->fk_tab = malloc(sizeof(pthread_mutex_t) * var->n_philos);
	if (!var->fk_tab)
		return ;	
}

void	init_mutex(t_data *var)
{
	int	i;

	i = -1;
	while (++i < var->n_philos)
		pthread_mutex_init(&(var->fk_tab[i]), NULL);
	pthread_mutex_init(&var->logs, NULL);
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
	init_mutex(var);
}

static int	check_last_arg(t_data *var)
{
	if (!(var->last_var >= (var->n_meals * var->n_philos)))
		return 0;
	return (1);
}

void	check_death(t_data *var)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < var->n_philos)
		{
			if (var->args == 5)
			{
				if (check_last_arg(var))
				{
					pthread_mutex_lock(&var->logs);	
					return ;
				}	

			}
			if ((exec_time() - var->ph_tab[i].t_last_meal) > var->t_die)
			{
				pthread_mutex_lock(&var->logs);
				printf("%ld %d died\n", (exec_time() - var->start_time), var->ph_tab[i].id + 1);
				return ;
			}
			usleep(50);
		}
	}
}
