/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:31:32 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/11 18:31:05 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fork_process(t_data *var, int last_arg)
{
	static int	i;
	int			pid;

	pid = fork();
	if (!pid)
	{
		var->ph_tab[i].t_last_meal = exec_time();
		if (pthread_create(&(var->ph_tab[i].thread), \
					NULL, &check_death, &var->ph_tab[i]))
			exit(0);
		if (last_arg == 4)
			routine_1(&var->ph_tab[i]);
		else
			routine_2(&var->ph_tab[i]);
	}
	i++;
	return (pid);
}

static void	kill_process(t_data *var, int iteration)
{
	while (iteration >= 0)
	{
		kill(var->pid_tab[iteration], SIGINT);
		iteration--;
	}
	exit(0);
}

void	thread_creat(t_data *var, int last_arg)
{
	int	i;
	int	exit_state;

	var->start_time = exec_time();
	i = -1;
	while (++i < var->n_philos)
	{
		var->pid_tab[i] = fork_process(var, last_arg);
		if (!(var->pid_tab[i]))
			kill_process(var, i);
	}
	while (waitpid(-1, &exit_state, 0) > 0)
	{
		if (exit_state == 256)
			kill_process(var, i);
	}
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
	thread_creat(&var, var.args);
	free_alloc(&var);
	return (0);
}
