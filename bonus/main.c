#include "philo.h"

static int	forkProcess(t_data *var, int lastArg)
{
	static int	i;
	int			pid;

	pid = fork();
	if (!pid)
	{
		var->phTab[i].tLastMeal = execTime();
		if(pthread_create(&(var->phTab[i].thread), NULL, &checkDeath, &var->phTab[i]))
			exit(0);
		if (lastArg == 4)
			routine_1(&var->phTab[i]);
		else
			routine_2(&var->phTab[i]);
	}
	i++;
	return (pid);
}

static void killProcess(t_data *var, int iteration)
{
	while (iteration >= 0)
	{
		kill(var->pidTab[iteration], SIGINT);
		iteration--;
	}
	exit(0);
}

void threadCreat(t_data *var, int lastArg)
{
	int	i;
	int	exitState;

	var->startTime = execTime();
	i = -1;
	while (++i < var->nPhilos)
	{
		var->pidTab[i] = forkProcess(var, lastArg);
		if (!(var->pidTab[i]))
			killProcess(var, i);
	}
	while (waitpid(-1, &exitState, 0) > 0)
	{
		if (exitState == 256)
			killProcess(var, i);
	}
}

int	main(int ac, char **av)
{
	t_data	var;

	if (ac == 1)
		return 0;
	var.args = ac - 1;
	if (!argsChecker(&av[1], var.args))
		ft_putstr("Wrong args\n");
	initArgs(av, &var);
	initPhilos(&var);
	threadCreat(&var, var.args);
	return (0);
}