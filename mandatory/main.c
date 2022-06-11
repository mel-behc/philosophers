/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:30:54 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/11 18:40:10 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_logs(t_data *var, char *log, int philo_id)
{
	pthread_mutex_lock(&var->logs);
	printf("%ld %d %s\n", (exec_time() - var->start_time), philo_id, log);
	pthread_mutex_unlock(&var->logs);
}

static void	*routine(void *param)
{
	t_philo	*philo;
	t_data	*var;

	philo = (t_philo *)param;
	var = philo->infos;
	var->last_var = 0;
	if (philo->id % 2)
		ft_usleep(100);
	while (1)
	{
		pthread_mutex_lock(&var->fk_tab[philo->l_fork]);
		print_logs(var, "has taken a fork", philo->id + 1);
		pthread_mutex_lock(&var->fk_tab[philo->r_fork]);
		print_logs(var, "has taken a fork", philo->id + 1);
		print_logs(var, "is eating", philo->id + 1);
		philo->t_last_meal = exec_time();
		ft_usleep(var->t_eat);
		pthread_mutex_unlock(&var->fk_tab[philo->l_fork]);
		pthread_mutex_unlock(&var->fk_tab[philo->r_fork]);
		var->last_var++;
		print_logs(var, "is sleeping", philo->id + 1);
		ft_usleep(var->t_sleep);
		print_logs(var, "is thinking", philo->id + 1);
	}
}

void	thread_creat(t_data *var)
{
	int	i;

	i = -1;
	var->start_time = exec_time();
	while (++i < var->n_philos)
	{
		var->ph_tab[i].t_last_meal = exec_time();
		pthread_create(&(var->ph_tab[i].thread), NULL, \
				&routine, &var->ph_tab[i]);
	}
	check_death(var);
}

int	main(int ac, char **av)
{
	t_data	var;

	var.args = ac - 1;
	if (!args_checker(&av[1], var.args))
	{
		ft_putstr("Wrong args\n");
		return (0);
	}
	init_args(av, &var);
	init_philos(&var);
	thread_creat(&var);
	free_alloc(&var, 1);
	return (0);
}
