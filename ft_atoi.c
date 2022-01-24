#include "push_swap.h"

int	ft_atoi(const char *str, int *flag)
{
	long long	i;
	long long	nb;
	long long	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + sign * (str[i] - '0');
		i++;
	}
	if (nb > 2147483647 || nb < -2147483648)
		*flag = 1;
	return ((int)nb);
}
