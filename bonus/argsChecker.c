/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsChecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melbehchach <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:31:12 by melbehchach       #+#    #+#             */
/*   Updated: 2022/06/08 03:31:14 by melbehchach      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int strChecker(char *str)
{
    int i;
    long arg;

    i = -1;
    while (str[++i])
    {
        if (!ft_isdigit(str[i]))
            break;
    }
    if (str[i] == '\0')
    {
        arg = ft_atol(str);
        if ((arg > 0 && arg < 2147483647))
            return 1;
    }
    return 0;
}

int argsChecker(char **str, int nOfargs)
{
    int i;

    i = 0;
    while (i < nOfargs)
    {
        if(!strChecker(str[i]))
            return 0;
        i++;
    }
    return 1;
}
