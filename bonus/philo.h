/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:31:39 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/11 18:33:16 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	thread;
	int		id;
	long		t_last_meal;
	int		l_fork;
	int		r_fork;
	struct s_data	*infos;
}	t_philo;

typedef struct s_data
{
	int		args;
	int		n_philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_meals;
	int		last_var;
	long		start_time;
	sem_t		*fk_tab;
	sem_t		*logs;
	int		*pid_tab;
	struct s_philo	*ph_tab;
}   t_data;

long	ft_atol(const char *str);
void	ft_putstr(char *s);
int	args_checker(char **str, int nOfargs);
long	exec_time(void);
void	ft_usleep(int time);
void	init_args(char **args, t_data *var);
void	init_philos(t_data *var);
void	init_sem(t_data *var);
void	*check_death(void *args);
void	thread_creat(t_data *var, int lastArg);
void	*routine_1(t_philo *philo);
void	*routine_2(t_philo *philo);
void	free_alloc(t_data *var);
#endif
