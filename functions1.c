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

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

// long long	ft_time(void)
// {
// 	struct timeval	pTime;
// 	long long		timestamp;

// 	gettimeofday(&pTime, NULL);
// 	timestamp = pTime.tv_sec * 1000;
// 	timestamp += pTime.tv_usec / 1000;
// 	return (timestamp);
// }

// void	ft_usleep(int time)
// {
// 	long long	breakTime;

// 	breakTime = ft_time() + time;
// 	while (ft_time() < breakTime)
// 		usleep(50);
// }