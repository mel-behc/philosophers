/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsChecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:30:27 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/11 18:35:54 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	str_checker(char *str)
{
	int		i;
	long	arg;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			break ;
	}
	if (str[i] == '\0')
	{
		arg = ft_atol(str);
		if ((arg > 0 && arg < 2147483647))
			return (1);
	}
	return (0);
}

int	args_checker(char **str, int n_of_args)
{
	int	i;

	i = 0;
	if (n_of_args < 4 || n_of_args > 5)
		return (0);
	while (i < n_of_args)
	{
		if (!str_checker(str[i]))
			return (0);
		i++;
	}
	return (1);
}
