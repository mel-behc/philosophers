#include "philo.h"

int strChecker(char *str)
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