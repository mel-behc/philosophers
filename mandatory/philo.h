/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:31:02 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/11 18:35:10 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	long			t_last_meal;
	int				l_fork;
	int				r_fork;
	struct s_data	*infos;
}	t_philo;

typedef struct s_data
{
	int				args;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	int				last_var;
	long			start_time;
	pthread_mutex_t	*fk_tab;
	pthread_mutex_t	logs;
	struct s_philo	*ph_tab;
}	t_data;

long	ft_atol(const char *str);
void	ft_putstr(char *s);
int		args_checker(char **str, int n_of_args);
long	exec_time(void);
void	ft_usleep(int time);
void	init_args(char **args, t_data *var);
void	init_philos(t_data *var);
void	init_mutex(t_data *var);
void	check_death(t_data *var);
void	thread_creat(t_data *var);
void	free_alloc(t_data *var, int tmp);
#endif
