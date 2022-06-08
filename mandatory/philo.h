/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:31:02 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/08 03:31:04 by melbehchach      ###   ########.fr       */
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
	pthread_t			thread;
	int					id;
	long				tLastMeal;
	int					lFork;
	int					rFork;
	struct s_data		*infos;
}	t_philo;

typedef struct s_data
{
	int				args;
	int				nPhilos;
	int				tDie;
	int				tEat;
	int				tSleep;
	int				nMeals;
	int				lastVar;
	long		    startTime;
	pthread_mutex_t *fkTab;
	pthread_mutex_t logs;
	struct s_philo	*phTab;
}   t_data;



long    ft_atol(const char *str);
void    ft_putstr(char *s);
int		argsChecker(char **str, int nOfargs);
long    execTime(void);
void	ft_usleep(int time);
void	initArgs(char **args, t_data *var);
void	initPhilos(t_data *var);
void	initMutex(t_data *var);
void	checkDeath(t_data *var);
void	threadCreat(t_data *var);
void	freeAlloc(t_data *var, int tmp);
#endif
