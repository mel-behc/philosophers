#include "philo.h"

int main(int ac, char **av)
{
    t_data vars;
    
    if (ac == 1)
        return 0;
    vars.nPhilosophers = ac - 1;
    if (!argsChecker(&av[1], vars.nPhilosophers))
        ft_putstr("Wrong args\n");
    // vars.nPhilosophers = ft_atoi(av[vars.i]);
}