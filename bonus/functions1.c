/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:31:20 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/11 18:29:49 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	int		i;
	long	number;
	int		signe;

	i = 0;
	number = 0;
	signe = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		number = (number * 10) + str[i] - '0';
		i++;
	}
	return (number * signe);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s != NULL)
	{
		while (s[++i])
			write(1, &s[i], 1);
	}
}

long	exec_time(void)
{
	struct timeval	time;
	long			time_return;

	gettimeofday(&time, NULL);
	time_return = time.tv_sec * 1000;
	time_return += time.tv_usec / 1000;
	return (time_return);
}

void	ft_usleep(int time)
{
	long	stop_time;

	stop_time = exec_time() + time;
	while (exec_time() < stop_time)
		usleep(50);
	return ;
}

void	free_alloc(t_data *var)
{
	free(var->ph_tab);
	free(var->pid_tab);
}
