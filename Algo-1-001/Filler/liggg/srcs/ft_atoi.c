#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (!str)
		return (0);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
		if (ft_isdigit(*str) == 0)
			return (0);
	}
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - 48;
	return (sign * result);
}
