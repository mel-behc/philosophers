#include "philo.h"

int argsChecker(char **str, int nOfargs)
{
    int i;
    int j;
    int arg;

    i = -1;
    while (str[++i])
    {
        printf("befor %d\n", i);
        arg = ft_atoi(str[i]);
        if (arg < -2147483648 || arg > 2147483647 || arg < 0)
        {
            ft_putstr("Error\n");
            break;
        }
        j = -1;
        while (str[i][++j])
        {
            if (!ft_isdigit(str[i][j]))
            {
                ft_putstr("Error\n");
                break;
            }
        }
        printf("after %d\n", i);
    }
    printf("number of args == %d and iterations == %d", nOfargs, i);
    if (i != nOfargs)
        return 0;
    return 1;
}

int main(int ac, char **av)
{
    t_data vars;
    
    if (ac == 1)
        return 0;
    vars.nPhilosophers = ac - 1;
    // argsChecker(&av[1], vars.nPhilosophers);
    if (!argsChecker(&av[1], vars.nPhilosophers))
        ft_putstr("Error\n");
    // vars.nPhilosophers = ft_atoi(av[vars.i]);
}